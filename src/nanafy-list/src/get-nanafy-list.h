#include <stddef.h>

#define DEFINE_GET_NANAFY_LIST(name, type)\
int get_nanafy_ ## name ## _list (size_t index, nanafy_ ## name ## _list *list, type *valuep){\
if (index < list->seek){\
*valuep = list->sequence[index];\
return 0;\
}\
return 1;\
}

#define DECLARE_GET_NANAFY_LIST(name, type)\
extern int get_nanafy_ ## name ## _list (size_t, nanafy_ ## name ## _list*, type*);
