#include <stddef.h>

#define DEFINE_COPY_NANAFY_LIST(name, type)\
int copy_nanafy_ ## name ## _list (nanafy_ ## name ## _list *listfrom, nanafy_ ## name ## _list *listto){\
if (listfrom->seek <= listto->size){\
for (size_t index = 0; index < listfrom->seek; index++){\
listto->sequence[index] = listfrom->sequence[index];\
}\
listto->seek = listfrom->seek;\
return 0;\
}\
return 1;\
}

#define DECLARE_COPY_NANAFY_LIST(name, type)\
extern int copy_nanafy_ ## name ## _list (nanafy_ ## name ## _list*, nanafy_ ## name ## _list*);
