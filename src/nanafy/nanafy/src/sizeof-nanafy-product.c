#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_product (nanafy *nana){
	return 
		sizeof_nanafy_image_file_header_product(nana) + 
		sizeof_nanafy_all_image_section_header_product(nana) + 
		sizeof_nanafy_all_section_product(nana) + 
		sizeof_nanafy_all_section_relocation_product(nana) + 
		sizeof_nanafy_symbol_list_product(&(nana->symbol_list)) + 
		sizeof_nanafy_symname_table_product(&(nana->symname_table));
}
