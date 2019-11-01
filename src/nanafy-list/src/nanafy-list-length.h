#include <stddef.h>

#define DEFINE_NANAFY_LIST_LENGTH(name, type)\
size_t nanafy_ ## name ## _list_length (nanafy_ ## name ## _list *list){\
return list->seek;\
}

#define DECLARE_NANAFY_LIST_LENGTH(name, type)\
extern size_t nanafy_ ## name ## _list_length (nanafy_ ## name ## _list*);
