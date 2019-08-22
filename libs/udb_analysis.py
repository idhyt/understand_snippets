#!/usr/bin/env python3
# encoding: utf-8
"""
@author:     'idhyt'
@date:       '25/04/2017'
@description:
            understand script
"""

import sys
from libs import common


class UdbAnalysis(object):
    def __init__(self, udb_file_path):
        if not isinstance(udb_file_path, str):
            raise TypeError

        self.__udb_file_path = udb_file_path
        self.__understand_db = None
        self.__func_call_level = None

    def __clean(self):
        self.__understand_db = None
        self.__func_call_level = None

    def set_understand_udb(self, udb_file_path):
        if not isinstance(udb_file_path, str):
            raise TypeError
        self.__udb_file_path = udb_file_path
        self.__clean()

    def get_understand_db(self):
        if self.__understand_db is None:
            if "win32" in sys.platform:
                from understand.windows.pc_win64.Python import understand
            elif "darwin" in sys.platform:
                from understand.macos.MacOS.Python import understand
            else:
                common.log("[-] Unable to identify the current platform: %s" % sys.platform)
                exit(-1)

            self.__understand_db = understand.open(self.__udb_file_path)

        return self.__understand_db

    def get_func_call_level(self, ignore_no_param=False):
        """
        获取udb中所有函数最短层级
        :param ignore_no_param: 是否忽略不带参数的函数
        :return:
        """

        if self.__func_call_level is not None:
            return self.__func_call_level

        self.__func_call_level = {}

        db = self.get_understand_db()

        call_by_list = []
        blank_space_list = []

        # for func in db.ents("function, method, procedure"):
        for func in db.ents("function ~unresolved ~unknown"):
            # ignore func which no param
            if ignore_no_param is True and not func.parameters():
                continue

            func_longname = func.longname()
            if "." in func_longname:
                continue

            # debug
            if func_longname == "tty_port_open":     # ""copy_from_read_buf":
                print("debug")

            call_by = 0
            del call_by_list[:]
            del blank_space_list[:]

            lines = func.ib("{Metrics}=off;{calls}=off;{callbys}levels=-1;"
                            "{references}=off;{parameters}=off;{defined in}=off;"
                            "{Variables}=off;{return type}=off;{Macros Used}=off;"
                            "{Globals Used}=off;")
            for line in lines:
                if "Called By" in line:
                    call_by = 1
                    continue

                if call_by:
                    call_by_list.append(line)

            if call_by == 0:
                func_level = 0
                level_info = "%s: %d" % (func_longname, func_level)
                common.log("[+] %s" % level_info)
                if str(func_level) not in self.__func_call_level:
                    self.__func_call_level.setdefault(str(func_level), [])

                self.__func_call_level[str(func_level)].append(func_longname)
                continue

            # calc level
            for call in call_by_list:
                char_list = list(call)
                blank_num = 0
                for char in char_list:
                    if char == " ":
                        blank_num += 1
                    else:
                        break
                blank_space_list.append(blank_num)

            # 寻找最短路径
            dups = common.find_dups(blank_space_list)
            depth = []
            if len(dups) > 0:
                min_dup_blank = min(dups)
                depth = [i for i in set(blank_space_list) if i <= min_dup_blank]

            if len(dups) == 0 and len(call_by_list) == 1:
                func_level = len(depth) + 1
            else:
                func_level = len(depth) + 2

            level_info = "%s: %d" % (func_longname, func_level)
            common.log("[+] %s" % level_info)

            if str(func_level) not in self.__func_call_level:
                self.__func_call_level.setdefault(str(func_level), [])

            self.__func_call_level[str(func_level)].append(func_longname)

        return self.__func_call_level

    def get_has_param_func_call_level(self):
        self.__func_call_level = None
        return self.get_func_call_level(ignore_no_param=True)

    def dump_has_param_func_level(self, dump_path):
        all_func_level = self.get_has_param_func_call_level()
        common.json_dump(dump_path, all_func_level)

    def get_func_xrefs_file(self, func_list, xrefs_file_flag, xrefs_file):
        """
        get func xrefs source file
        :param func_list: ["func1", "func2", ...]
        :param xrefs_file_flag: the source file path flag, example, "drivers"
        :param xrefs_file: to return, like ["file1", "file2", ...]
        :return: if find all, return True, else return False
        """
        if not isinstance(func_list, list) or not isinstance(xrefs_file_flag, str) or not isinstance(xrefs_file, dict):
            raise TypeError

        db = self.get_understand_db()

        flag = xrefs_file_flag

        total_num = 0
        # for func in db.ents("function, method, procedure"):
        for func in db.ents("function ~unresolved ~unknown"):
            try:
                func_longname = func.longname()

                if func_longname in func_list:
                    parent_name = func.parent().longname()
                    file_name = flag + parent_name.split(flag)[-1].strip()
                    if file_name not in xrefs_file:
                        xrefs_file.setdefault(file_name, [])
                    xrefs_file[file_name].append(func_longname)
                    total_num += 1
                    common.log("[+] find %s in %s %d" % (func_longname, file_name, total_num))
            except Exception as err:
                print("[-] %s of %s" % (str(err), func_longname))

        if len(func_list) > total_num:
            print("[-] find func num is %s, but already find num is %d" % (len(func_list), total_num))
            return False

        return True



