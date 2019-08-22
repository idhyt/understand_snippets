## understand_snippets

understand脚本运行环境

## env

`macos`: 直接使用

`windows`: 需要将`understand/windows/pc_win64`加入系统环境变量

## run test

python3 test.py

```
$ python3 test.py
[   *] [func_name]                   :[func_param]
[   1] __dislocator_alloc            :size_t len
[   2] fprintf                       :
[   3] abort                         :
[   4] mmap                          :
[   5] mprotect                      :
[   6] calloc                        :size_t elem_len,size_t elem_cnt
[   7] malloc                        :size_t len
[   8] memset                        :
[   9] free                          :void *ptr
[  10] realloc                       :void *ptr,size_t len
[  11] memcpy                        :
[  12] getenv                        :
[  13] atoi                          :
[  14] __tokencap_load_mappings      :
[  15] fopen                         :
[  16] fgets                         :
[  17] sscanf                        :
[  18] fclose                        :
[  19] __tokencap_is_ro              :const void *ptr
[  20] __tokencap_dump               :const u8 *ptr,size_t len,u8 is_text
[  21] sprintf                       :
[  22] strcmp                        :const char *str1,const char *str2
[  23] strlen                        :
[  24] strncmp                       :const char *str1,const char *str2,size_t len
[  25] strcasecmp                    :const char *str1,const char *str2
[  26] tolower                       :
[  27] strncasecmp                   :const char *str1,const char *str2,size_t len
[  28] memcmp                        :const void *mem1,const void *mem2,size_t len
...
...

```

## issue

understand.UnderstandError: NoApiLicense

`macos`: copy `understand_snippets/*` to `Understand.app` directory, then run.
