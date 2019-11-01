#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFINE_EXTEND_NANAFY_ARRAY(name, type)\
int extend_nanafy_ ## name ## _array(type defvalue, size_t exsize, nanafy_ ## name ## _array *array){\
size_t newsize = array->size + exsize;\
type *newseq = realloc(array->sequence, sizeof(type) * newsize);\
if (newseq == NULL){\
return 1;\
}\
else {\
for (size_t index = 0; index < exsize; index++){\
newseq[array->size + index] = defvalue;\
}\
array->sequence = newseq;\
array->size = newsize;\
return 0;\
}\
}

#define DECLARE_EXTEND_NANAFY_ARRAY(name, type)\
extern int extend_nanafy_ ## name ## _array(type, size_t, nanafy_ ## name ## _array*);
