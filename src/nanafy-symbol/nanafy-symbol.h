#include <stddef.h>
#include <stdbool.h>

extern void init_nanafy_symbol (nanafy_section, size_t, size_t, nanafy_symbol*);
#include <stddef.h>
#include <stdbool.h>

extern void init_nanafy_external_symbol (size_t, nanafy_symbol*);
#include <stddef.h>

extern size_t nanafy_symbol_symname_offset (nanafy_symbol*);
#include <stdbool.h>
#include <windows.h>

extern int setup_image_symbol_with_nanafy_symbol (nanafy_symbol*, nanafy*, IMAGE_SYMBOL*);
#include <stddef.h>
#include <windows.h>

extern size_t sizeof_nanafy_symbol_product (nanafy_symbol*);
#include <stddef.h>
#include <windows.h>

extern int read_nanafy_symbol_product (void*, size_t, size_t, nanafy_symbol*, nanafy*, size_t*);
#include <stddef.h>
#include <stdbool.h>

extern void init_nanafy_private_symbol (nanafy_section, size_t, size_t, nanafy_symbol*);
