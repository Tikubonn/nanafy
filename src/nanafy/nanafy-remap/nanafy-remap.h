#include <stddef.h>

extern int remap_nanafy_data_memory (void *sequence, size_t size, nanafy *nana);
#include <stddef.h>

extern int remap_nanafy_local_relocation_list (nanafy_local_relocation*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_text_relocation_list (nanafy_relocation*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_rodata_memory (void*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_symbol_list (nanafy_symbol*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_symname_table (void*, size_t, size_t*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_text_memory (void*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_data_relocation_list (nanafy_relocation*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_rodata_relocation_list (nanafy_relocation*, size_t, nanafy*);
