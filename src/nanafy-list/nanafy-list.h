#define DEFINE_NANAFY_LIST(name, type)\
DEFINE_INIT_NANAFY_LIST(name, type)\
DEFINE_SET_NANAFY_LIST(name, type)\
DEFINE_GET_NANAFY_LIST(name, type)\
DEFINE_ADD_NANAFY_LIST(name, type)\
DEFINE_NANAFY_LIST_LENGTH(name, type)\
DEFINE_COPY_NANAFY_LIST(name, type)\
DEFINE_EXTEND_NANAFY_LIST(name, type)\
DEFINE_FREE_NANAFY_LIST(name, type)\
DEFINE_HAS_NANAFY_LIST_MARGIN(name, type)

#define DECLARE_NANAFY_LIST(name, type)\
DEFINE_NANAFY_LIST_TYPE(name, type)\
DECLARE_INIT_NANAFY_LIST(name, type)\
DECLARE_SET_NANAFY_LIST(name, type)\
DECLARE_GET_NANAFY_LIST(name, type)\
DECLARE_ADD_NANAFY_LIST(name, type)\
DECLARE_NANAFY_LIST_LENGTH(name, type)\
DECLARE_COPY_NANAFY_LIST(name, type)\
DECLARE_EXTEND_NANAFY_LIST(name, type)\
DECLARE_FREE_NANAFY_LIST(name, type)\
DECLARE_HAS_NANAFY_LIST_MARGIN(name, type)
#include <stddef.h>

#define DEFINE_NANAFY_LIST_TYPE(name, type)\
typedef struct nanafy_ ## name ## _list {\
type *sequence;\
size_t seek;\
size_t size;\
} nanafy_ ## name ## _list;
#include <stddef.h>

#define DEFINE_INIT_NANAFY_LIST(name, type)\
void init_nanafy_ ## name ## _list (type *sequence, size_t size, nanafy_ ## name ## _list *list){\
list->sequence = sequence;\
list->seek = 0;\
list->size = size;\
}

#define DECLARE_INIT_NANAFY_LIST(name, type)\
extern void init_nanafy_ ## name ## _list (type*, size_t, nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_GET_NANAFY_LIST(name, type)\
int get_nanafy_ ## name ## _list (size_t index, nanafy_ ## name ## _list *list, type *valuep){\
if (index < list->seek){\
*valuep = list->sequence[index];\
return 0;\
}\
return 1;\
}

#define DECLARE_GET_NANAFY_LIST(name, type)\
extern int get_nanafy_ ## name ## _list (size_t, nanafy_ ## name ## _list*, type*);
#include <stddef.h>

#define DEFINE_SET_NANAFY_LIST(name, type)\
int set_nanafy_ ## name ## _list (type value, size_t index, nanafy_ ## name ## _list *list){\
if (index < list->seek){\
list->sequence[index] = value;\
return 0;\
}\
return 1;\
}

#define DECLARE_SET_NANAFY_LIST(name, type)\
extern int set_nanafy_ ## name ## _list (type, size_t, nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_ADD_NANAFY_LIST(name, type)\
int add_nanafy_ ## name ## _list (type value, nanafy_ ## name ## _list *list, size_t *indexp){\
if (list->seek < list->size){\
*indexp = list->seek;\
list->sequence[list->seek] = value;\
list->seek += 1;\
return 0;\
}\
return 1;\
}

#define DECLARE_ADD_NANAFY_LIST(name, type)\
extern int add_nanafy_ ## name ## _list (type, nanafy_ ## name ## _list*, size_t*);
#include <stddef.h>

#define DEFINE_NANAFY_LIST_LENGTH(name, type)\
size_t nanafy_ ## name ## _list_length (nanafy_ ## name ## _list *list){\
return list->seek;\
}

#define DECLARE_NANAFY_LIST_LENGTH(name, type)\
extern size_t nanafy_ ## name ## _list_length (nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_COPY_NANAFY_LIST(name, type)\
int copy_nanafy_ ## name ## _list (nanafy_ ## name ## _list *listfrom, nanafy_ ## name ## _list *listto){\
if (listfrom->seek <= listto->size){\
for (size_t index = 0; index < listfrom->seek; index++){\
listto->sequence[index] = listfrom->sequence[index];\
}\
listto->seek = listfrom->seek;\
return 0;\
}\
return 1;\
}

#define DECLARE_COPY_NANAFY_LIST(name, type)\
extern int copy_nanafy_ ## name ## _list (nanafy_ ## name ## _list*, nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_EXTEND_NANAFY_LIST(name, type)\
int extend_nanafy_ ## name ## _list (size_t exsize, nanafy_ ## name ## _list *list){\
size_t newsize = list->size + exsize;\
type *newseq = realloc(list->sequence, sizeof(type) * newsize);\
if (newseq == NULL){\
return 1;\
}\
else {\
list->sequence = newseq;\
list->size = newsize;\
return 0;\
}\
}

#define DECLARE_EXTEND_NANAFY_LIST(name, type)\
extern int extend_nanafy_ ## name ## _list (size_t, nanafy_ ## name ## _list*);
#include <stddef.h>
#include <stdlib.h>

#define DEFINE_FREE_NANAFY_LIST(name, type)\
void free_nanafy_ ## name ## _list (nanafy_ ## name ## _list *list){\
if (list->sequence != NULL){\
free(list->sequence);\
}\
}

#define DECLARE_FREE_NANAFY_LIST(name, type)\
extern void free_nanafy_ ## name ## _list (nanafy_ ## name ## _list*);
#include <stddef.h>
#include <stdbool.h>

#define DEFINE_HAS_NANAFY_LIST_MARGIN(name, type)\
bool has_nanafy_ ## name ## _list_margin (size_t size, nanafy_ ## name ## _list *list){\
return list->seek + size <= list->size;\
}

#define DECLARE_HAS_NANAFY_LIST_MARGIN(name, type)\
extern bool has_nanafy_ ## name ## _list_margin (size_t, nanafy_ ## name ## _list*);
