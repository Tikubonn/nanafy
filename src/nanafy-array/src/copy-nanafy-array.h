#include <stddef.h>

#define DEFINE_COPY_NANAFY_ARRAY(name, type)\
int copy_nanafy_ ## name ## _array(nanafy_ ## name ## _array *arrayfrom, nanafy_ ## name ## _array *arrayto){\
if (arrayfrom->size <= arrayto->size){\
for (size_t index = 0; index < arrayfrom->size; index++){\
arrayto->sequence[index] = arrayfrom->sequence[index];\
}\
return 0;\
}\
return 1;\
}

#define DECLARE_COPY_NANAFY_ARRAY(name, type)\
extern int copy_nanafy_ ## name ## _array(nanafy_ ## name ## _array*, nanafy_ ## name ## _array*);
