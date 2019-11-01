#include <stddef.h>

#define DEFINE_NANAFY_ARRAY_TYPE(name, type)\
typedef struct nanafy_ ## name ## _array {\
type *sequence;\
size_t size;\
} nanafy_ ## name ## _array;
