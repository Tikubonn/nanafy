#include <stddef.h>

#define DEFINE_SET_NANAFY_ARRAY(name, type)\
int set_nanafy_ ## name ## _array(type value, size_t index, nanafy_ ## name ## _array *array){\
if (index < array->size){\
array->sequence[index] = value;\
return 0;\
}\
return 1;\
}

#define DECLARE_SET_NANAFY_ARRAY(name, type)\
extern int set_nanafy_ ## name ## _array(type, size_t, nanafy_ ## name ## _array*);
