#include <stddef.h>
#include <windows.h>

extern int setup_image_file_header_with_nanafy (nanafy*, IMAGE_FILE_HEADER*);
#include <stddef.h>

extern size_t sizeof_nanafy_image_file_header_product (nanafy*);
#include <stddef.h>

extern int read_nanafy_image_file_header_product (void*, size_t, size_t, nanafy*, size_t*);
#include <stddef.h>

extern void init_nanafy (
	void*,
	size_t,
	void*,
	size_t,
	void*,
	size_t,
	nanafy_symbol*,
	size_t,
	void*,
	size_t,
	size_t*,
	size_t,
	nanafy_symname_table_hash_func,
	nanafy_relocation*,
	size_t,
	nanafy_relocation*,
	size_t,
	nanafy_relocation*,
	size_t,
	nanafy_local_relocation*,
	size_t,
	nanafy_info*,
	nanafy*);
#include <stddef.h>

extern nanafy *make_nanafy (
	size_t,
	size_t,
	size_t,
	size_t,
	size_t,
	size_t,
	nanafy_symname_table_hash_func,
	size_t,
	size_t,
	size_t,
	size_t,
	nanafy_info*);
#include <stdlib.h>

extern void free_nanafy (nanafy*);
#include <stddef.h>

extern size_t sizeof_nanafy_product (nanafy*);
#include <stddef.h>

extern int read_nanafy_product (void*, size_t, size_t, nanafy*, size_t*);

extern void init_empty_nanafy (nanafy_symname_table_hash_func, nanafy_info*, nanafy*);
#include <nanafy.h>

extern nanafy *make_empty_nanafy (nanafy_symname_table_hash_func, nanafy_info*);
