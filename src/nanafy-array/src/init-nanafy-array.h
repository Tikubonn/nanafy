#include <stddef.h>

#define DEFINE_INIT_NANAFY_ARRAY(name, type)\
void init_nanafy_ ## name ## _array(type *sequence, size_t size, nanafy_ ## name ## _array *array){\
array->sequence = sequence;\
array->size = size;\
}

#define DECLARE_INIT_NANAFY_ARRAY(name, type)\
extern void init_nanafy_ ## name ## _array(type*, size_t, nanafy_ ## name ## _array*);
