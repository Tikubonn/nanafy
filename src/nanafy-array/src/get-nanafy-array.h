#include <stddef.h>

#define DEFINE_GET_NANAFY_ARRAY(name, type)\
int get_nanafy_ ## name ## _array(size_t index, nanafy_ ## name ## _array *array, type *valuep){\
if (index < array->size){\
*valuep = array->sequence[index];\
return 0;\
}\
return 1;\
}

#define DECLARE_GET_NANAFY_ARRAY(name, type)\
extern int get_nanafy_ ## name ## _array(size_t, nanafy_ ## name ## _array*, type*);
