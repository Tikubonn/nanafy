#include <stddef.h>

extern void init_nanafy_relative_relocation (size_t, size_t, size_t, nanafy_relocation*);
#include <stddef.h>
#include <windows.h>

extern int setup_image_relocation_with_nanafy_relocation (nanafy_section, nanafy_relocation*, nanafy*, IMAGE_RELOCATION*);
#include <stddef.h>

extern size_t sizeof_nanafy_relocation_product (nanafy_section, nanafy_relocation*);
#include <stddef.h>

extern int read_nanafy_relocation_product (void*, size_t, size_t, nanafy_section, nanafy_relocation*, nanafy*, size_t*);
#include <stddef.h>

extern void init_nanafy_relocation (size_t, size_t, size_t, nanafy_relocation*);
