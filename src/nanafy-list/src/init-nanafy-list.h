#include <stddef.h>

#define DEFINE_INIT_NANAFY_LIST(name, type)\
void init_nanafy_ ## name ## _list (type *sequence, size_t size, nanafy_ ## name ## _list *list){\
list->sequence = sequence;\
list->seek = 0;\
list->size = size;\
}

#define DECLARE_INIT_NANAFY_LIST(name, type)\
extern void init_nanafy_ ## name ## _list (type*, size_t, nanafy_ ## name ## _list*);
