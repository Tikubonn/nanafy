#include <stddef.h>

extern void init_nanafy_uninited_memory (nanafy_uninited_memory*);
#include <stddef.h>

extern void allocate_nanafy_uninited_memory (size_t, nanafy_uninited_memory*);
#include <stddef.h>

extern void align_nanafy_uninited_memory (size_t, nanafy_uninited_memory*);
#include <stddef.h>

extern size_t tell_nanafy_uninited_memory (nanafy_uninited_memory*);
#include <stddef.h>

extern size_t sizeof_nanafy_uninited_memory_product (nanafy_uninited_memory*);
#include <stddef.h>

extern int read_nanafy_uninited_memory_product (void*, size_t, size_t, nanafy_uninited_memory*, size_t*);
