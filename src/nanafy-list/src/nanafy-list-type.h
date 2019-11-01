#include <stddef.h>

#define DEFINE_NANAFY_LIST_TYPE(name, type)\
typedef struct nanafy_ ## name ## _list {\
type *sequence;\
size_t seek;\
size_t size;\
} nanafy_ ## name ## _list;
