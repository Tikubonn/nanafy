#define DEFINE_NANAFY_ARRAY(name, type)\
DEFINE_INIT_NANAFY_ARRAY(name, type)\
DEFINE_SET_NANAFY_ARRAY(name, type)\
DEFINE_GET_NANAFY_ARRAY(name, type)\
DEFINE_NANAFY_ARRAY_LENGTH(name, type)\
DEFINE_CLEAR_NANAFY_ARRAY(name, type)\
DEFINE_COPY_NANAFY_ARRAY(name, type)\
DEFINE_EXTEND_NANAFY_ARRAY(name, type)\
DEFINE_FREE_NANAFY_ARRAY(name, type)

#define DECLARE_NANAFY_ARRAY(name, type)\
DEFINE_NANAFY_ARRAY_TYPE(name, type)\
DECLARE_INIT_NANAFY_ARRAY(name, type)\
DECLARE_SET_NANAFY_ARRAY(name, type)\
DECLARE_GET_NANAFY_ARRAY(name, type)\
DECLARE_NANAFY_ARRAY_LENGTH(name, type)\
DECLARE_CLEAR_NANAFY_ARRAY(name, type)\
DECLARE_COPY_NANAFY_ARRAY(name, type)\
DECLARE_EXTEND_NANAFY_ARRAY(name, type)\
DECLARE_FREE_NANAFY_ARRAY(name, type)
#include <stddef.h>

#define DEFINE_NANAFY_ARRAY_TYPE(name, type)\
typedef struct nanafy_ ## name ## _array {\
type *sequence;\
size_t size;\
} nanafy_ ## name ## _array;
#include <stddef.h>

#define DEFINE_INIT_NANAFY_ARRAY(name, type)\
void init_nanafy_ ## name ## _array(type *sequence, size_t size, nanafy_ ## name ## _array *array){\
array->sequence = sequence;\
array->size = size;\
}

#define DECLARE_INIT_NANAFY_ARRAY(name, type)\
extern void init_nanafy_ ## name ## _array(type*, size_t, nanafy_ ## name ## _array*);
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
#include <stddef.h>

#define DEFINE_NANAFY_ARRAY_LENGTH(name, type)\
size_t nanafy_ ## name ## _array_length(nanafy_ ## name ## _array *array){\
return array->size;\
}

#define DECLARE_NANAFY_ARRAY_LENGTH(name, type)\
extern size_t nanafy_ ## name ## _array_length(nanafy_ ## name ## _array*);
#include <stddef.h>

#define DEFINE_CLEAR_NANAFY_ARRAY(name, type)\
void clear_nanafy_ ## name ## _array(type value, nanafy_ ## name ## _array *array){\
for (size_t index = 0; index < array->size; index++){\
array->sequence[index] = value;\
}\
}

#define DECLARE_CLEAR_NANAFY_ARRAY(name, type)\
extern void clear_nanafy_ ## name ## _array(type, nanafy_ ## name ## _array*);
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
