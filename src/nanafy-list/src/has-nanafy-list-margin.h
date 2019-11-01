#include <stddef.h>
#include <stdbool.h>

#define DEFINE_HAS_NANAFY_LIST_MARGIN(name, type)\
bool has_nanafy_ ## name ## _list_margin (size_t size, nanafy_ ## name ## _list *list){\
return list->seek + size <= list->size;\
}

#define DECLARE_HAS_NANAFY_LIST_MARGIN(name, type)\
extern bool has_nanafy_ ## name ## _list_margin (size_t, nanafy_ ## name ## _list*);
