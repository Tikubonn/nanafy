#include <stddef.h>

extern void init_nanafy_memory (void*, size_t, nanafy_memory*);
#include <stddef.h>

extern int put_nanafy_memory (int, nanafy_memory*);
#include <stddef.h>

extern int write_nanafy_memory (void*, size_t, nanafy_memory*);
#include <stddef.h>

extern size_t tell_nanafy_memory (nanafy_memory*);
#include <stddef.h>
#include <stdbool.h>

extern bool has_nanafy_memory_margin (size_t, nanafy_memory*);
#include <stddef.h>

extern int extend_nanafy_memory (size_t, nanafy_memory*);

extern void free_nanafy_memory (nanafy_memory*);
#include <stddef.h>

extern size_t sizeof_nanafy_memory_product (nanafy_memory*);
#include <stddef.h>

extern int read_nanafy_memory_product (void*, size_t, size_t, nanafy_memory*, size_t*);
#include <stddef.h>

extern int align_nanafy_memory (int, size_t, nanafy_memory*);
#include <stddef.h>

extern int set_nanafy_memory (int, size_t, nanafy_memory*);
#include <stddef.h>

extern int rewrite_nanafy_memory (void*, size_t, size_t, nanafy_memory*);

extern int copy_nanafy_memory (nanafy_memory*, nanafy_memory*);
