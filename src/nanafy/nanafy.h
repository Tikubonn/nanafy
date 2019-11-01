#include <stddef.h>

extern int put_nanafy_manually (int, nanafy_section, nanafy*);
#include <stddef.h>

extern int put_nanafy (int, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status write_nanafy_manually (void*, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern int write_nanafy (void*, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status align_nanafy_manually (int, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern int align_nanafy (int, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status allocate_nanafy_manually (size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern int allocate_nanafy (size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern size_t tell_nanafy (nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status register_nanafy_external_symbol_manually (char*, size_t, nanafy*, size_t*);
#include <stddef.h>

extern int register_nanafy_external_symbol (char*, size_t, nanafy*, size_t*);
#include <stddef.h>

extern nanafy_status register_nanafy_symbol_manually (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int register_nanafy_symbol (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern nanafy_status register_nanafy_private_symbol_manually (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int register_nanafy_private_symbol (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int put_nanafy_external_offset (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status put_nanafy_external_offset_manually (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>

extern int put_nanafy_external_relative_offset (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status put_nanafy_external_relative_offset_manually (size_t, nanafy_section, size_t, nanafy*);
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
#include <stddef.h>

extern nanafy_status put_nanafy_offset_manually (nanafy_section, size_t, size_t, nanafy*);
#include <stddef.h>

extern int put_nanafy_offset (nanafy_section, size_t, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status set_nanafy_offset_manually (nanafy_section sectionfrom, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana);
#include <stddef.h>

extern int set_nanafy_offset (nanafy_section, size_t, size_t, size_t, nanafy*);
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
