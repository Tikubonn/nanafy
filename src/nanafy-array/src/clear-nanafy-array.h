#include <stddef.h>

#define DEFINE_CLEAR_NANAFY_ARRAY(name, type)\
void clear_nanafy_ ## name ## _array(type value, nanafy_ ## name ## _array *array){\
for (size_t index = 0; index < array->size; index++){\
array->sequence[index] = value;\
}\
}

#define DECLARE_CLEAR_NANAFY_ARRAY(name, type)\
extern void clear_nanafy_ ## name ## _array(type, nanafy_ ## name ## _array*);
