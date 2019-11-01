#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_section_relocation_product (nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION:
			return sizeof_nanafy_relocation_list_product(NANAFY_TEXT_SECTION, &(nana->text_relocation_list));
		case NANAFY_DATA_SECTION:
			return sizeof_nanafy_relocation_list_product(NANAFY_DATA_SECTION, &(nana->data_relocation_list));
		case NANAFY_RODATA_SECTION:
			return sizeof_nanafy_relocation_list_product(NANAFY_RODATA_SECTION, &(nana->rodata_relocation_list));
		default:
			return 0;
	}
}
