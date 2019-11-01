#include <stddef.h>

extern void init_nanafy_buffer (void*, size_t, nanafy_buffer*);
#include <stddef.h>

extern int put_nanafy_buffer (int, nanafy_buffer*);
#include <stddef.h>

extern void write_nanafy_buffer (void*, size_t, nanafy_buffer*, size_t*);
#include <stddef.h>

extern size_t tell_nanafy_buffer (nanafy_buffer*);
#include <stddef.h>
#include <stdbool.h>

extern bool has_nanafy_buffer_margin (size_t, nanafy_buffer*);
#include <stddef.h>

extern size_t nanafy_buffer_size (nanafy_buffer *buffer);

extern void *nanafy_buffer_array (nanafy_buffer*);
#include <stddef.h>

extern int copy_nanafy_buffer (nanafy_buffer*, nanafy_buffer*);
#include <stddef.h>

extern int extend_nanafy_buffer (size_t, nanafy_buffer*);
#include <stdlib.h>

extern void free_nanafy_buffer (nanafy_buffer*);
