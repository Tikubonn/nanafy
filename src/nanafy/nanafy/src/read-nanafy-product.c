#include <nanafy.h>
#include <stddef.h>

int read_nanafy_product (void *sequence, size_t size, size_t offset, nanafy *nana, size_t *readsizep){
	// *fix 
	if (fix_nanafy_memory_with_local_relocation_list(&(nana->local_relocation_list), nana) != 0){
		return 1;
	}
	size_t off = offset;
	// *header
	{
		size_t si = sizeof_nanafy_image_file_header_product(nana);
		if (0 < si && off < si){
			return read_nanafy_image_file_header_product(sequence, size, off, nana, readsizep);
		}
		off -= si;
	}
	// *section
	{
		size_t si = sizeof_nanafy_all_image_section_header_product(nana);
		if (0 < si && off < si){
			return read_nanafy_all_image_section_header_product(sequence, size, off, nana, readsizep);
		}
		off -= si;
	}
	// *binary
	{
		size_t si = sizeof_nanafy_all_section_product(nana);
		if (0 < si && off < si){
			return read_nanafy_all_section_product(sequence, size, off, nana, readsizep);
		}
		off -= si;
	}
	// *relocation
	{
		size_t si = sizeof_nanafy_all_section_relocation_product(nana);
		if (0 < si && off < si){
			return read_nanafy_all_section_relocation_product(sequence, size, off, nana, readsizep);
		}
		off -= si;
	}
	// *symbol 
	{
		size_t si = sizeof_nanafy_symbol_list_product(&(nana->symbol_list));
		if (0 < si && off < si){
			return read_nanafy_symbol_list_product(sequence, size, off, &(nana->symbol_list), nana, readsizep);
		}
		off -= si;
	}
	// *symbol name table
	{
		size_t si = sizeof_nanafy_symname_table_product(&(nana->symname_table));
		if (0 < si && off < si){
			return read_nanafy_symname_table_product(sequence, size, off, &(nana->symname_table), readsizep);
		}
		off -= si;
	}
	// *eof
	*readsizep = 0;
	return 0;
}
