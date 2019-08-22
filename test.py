import sys
from libs import udb_analysis


if "win32" in sys.platform:
    from understand.windows.pc_win64.Python import understand
elif "darwin" in sys.platform:
    from understand.macos.MacOS.Python import understand
else:
    print("[-] Unable to identify the current platform: %s" % sys.platform)
    exit(-1)


def simple_test():
    test_udb = "test.udb"

    db = understand.open(test_udb)

    print("[%4s] %-30s:%s" % ("*", "[func_name]", "[func_param]"))
    total_num = 0

    for func in db.ents("function, method, procedure"):
        total_num += 1
        func_name = func.simplename()
        func_param = func.parameters()
        print("[%4d] %-30s:%s" % (total_num, func_name, func_param))


def func_level_test():
    test_udb = "func.udb"

    cudb = udb_analysis.UdbAnalysis(test_udb)

    cudb.dump_has_param_func_level("dump.json")


def test():
    # simple_test()
    func_level_test()


if __name__ == '__main__':

    test()
