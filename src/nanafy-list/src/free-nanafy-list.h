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
