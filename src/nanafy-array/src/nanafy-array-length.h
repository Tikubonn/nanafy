#include <stddef.h>

#define DEFINE_NANAFY_ARRAY_LENGTH(name, type)\
size_t nanafy_ ## name ## _array_length(nanafy_ ## name ## _array *array){\
return array->size;\
}

#define DECLARE_NANAFY_ARRAY_LENGTH(name, type)\
extern size_t nanafy_ ## name ## _array_length(nanafy_ ## name ## _array*);
