#include <nanafy.h>
#include <stddef.h>

size_t countof_nanafy_section_relocation_product (nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			return nanafy_relocation_list_length(&(nana->text_relocation_list));
		case NANAFY_DATA_SECTION: 
			return nanafy_relocation_list_length(&(nana->data_relocation_list));
		case NANAFY_RODATA_SECTION: 
			return nanafy_relocation_list_length(&(nana->rodata_relocation_list));
		default:
			return 0;
	}
}
