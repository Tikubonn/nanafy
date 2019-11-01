#include <stddef.h>
#include <stdlib.h>

#define DEFINE_FREE_NANAFY_ARRAY(name, type)\
void free_nanafy_ ## name ## _array(nanafy_ ## name ## _array *array){\
if (array->sequence != NULL){\
free(array->sequence);\
}\
}

#define DECLARE_FREE_NANAFY_ARRAY(name, type)\
extern void free_nanafy_ ## name ## _array(nanafy_ ## name ## _array*);
