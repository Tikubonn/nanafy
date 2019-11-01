#include <stddef.h>

#define DEFINE_SET_NANAFY_LIST(name, type)\
int set_nanafy_ ## name ## _list (type value, size_t index, nanafy_ ## name ## _list *list){\
if (index < list->seek){\
list->sequence[index] = value;\
return 0;\
}\
return 1;\
}

#define DECLARE_SET_NANAFY_LIST(name, type)\
extern int set_nanafy_ ## name ## _list (type, size_t, nanafy_ ## name ## _list*);
