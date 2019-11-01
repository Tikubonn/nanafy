#include <stddef.h>

#define DEFINE_EXTEND_NANAFY_LIST(name, type)\
int extend_nanafy_ ## name ## _list (size_t exsize, nanafy_ ## name ## _list *list){\
size_t newsize = list->size + exsize;\
type *newseq = realloc(list->sequence, sizeof(type) * newsize);\
if (newseq == NULL){\
return 1;\
}\
else {\
list->sequence = newseq;\
list->size = newsize;\
return 0;\
}\
}

#define DECLARE_EXTEND_NANAFY_LIST(name, type)\
extern int extend_nanafy_ ## name ## _list (size_t, nanafy_ ## name ## _list*);
