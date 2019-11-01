#include <stddef.h>

extern nanafy_status add_nanafy_symname_table (char*, size_t, nanafy_symname_table*, size_t*);
#include <stddef.h>

extern int copy_nanafy_symname_table (nanafy_symname_table*, nanafy_symname_table*);
#include <stddef.h>

extern int extend_nanafy_symname_table (size_t, size_t, nanafy_symname_table*);
#include <stddef.h>

extern int find_nanafy_symname_table (char*, size_t, nanafy_symname_table*, bool*, size_t*);

extern void free_nanafy_symname_table (nanafy_symname_table*);
#include <stddef.h>

extern void init_nanafy_symname_table (
	void*,
	size_t,
	size_t*,
	size_t,
	nanafy_symname_table_hash_func,
	nanafy_symname_table*);
#include <stddef.h>

extern int read_nanafy_symname_table_product (void*, size_t, size_t, nanafy_symname_table*, size_t*);
#include <stddef.h>

extern size_t sizeof_nanafy_symname_table_product (nanafy_symname_table*);
#include <stddef.h>

extern size_t NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC (char*, size_t);
