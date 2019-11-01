#include <stddef.h>

#define DEFINE_ADD_NANAFY_LIST(name, type)\
int add_nanafy_ ## name ## _list (type value, nanafy_ ## name ## _list *list, size_t *indexp){\
if (list->seek < list->size){\
*indexp = list->seek;\
list->sequence[list->seek] = value;\
list->seek += 1;\
return 0;\
}\
return 1;\
}

#define DECLARE_ADD_NANAFY_LIST(name, type)\
extern int add_nanafy_ ## name ## _list (type, nanafy_ ## name ## _list*, size_t*);
