#include <stdio.h>
#include <stdlib.h>

#define test(formula)\
if (formula){\
printf("[success] %s:%d %s\n", __FILE__, __LINE__, #formula);\
}\
else {\
printf("[error] %s:%d %s\n", __FILE__, __LINE__, #formula);\
abort();\
}

#define test_equal_string(a, b) {\
char *address1 = a;\
char *address2 = b;\
char *addr1 = address1;\
char *addr2 = address2;\
while (1){\
if (*addr1 == '\0' && *addr2 == '\0'){\
printf("[success] %s:%d %s != %s\n", __FILE__, __LINE__, #a, #b);\
break;\
}\
else if (*addr1 != *addr2){\
printf("[error] %s:%d %s != %s (\"%s\" != \"%s\")\n", __FILE__, __LINE__, #a, #b, address1, address2);\
abort();\
}\
addr1++;\
addr2++;\
}\
}
