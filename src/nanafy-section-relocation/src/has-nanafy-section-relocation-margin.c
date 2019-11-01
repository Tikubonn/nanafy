#include <nanafy.h>
#include <stddef.h>

nanafy_status has_nanafy_section_relocation_margin (size_t size, nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION:
			if (has_nanafy_relocation_list_margin(size, &(nana->text_relocation_list)) == false){
				return NANAFY_TEXT_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_DATA_SECTION:
			if (has_nanafy_relocation_list_margin(size, &(nana->data_relocation_list)) == false){
				return NANAFY_DATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_RODATA_SECTION:
			if (has_nanafy_relocation_list_margin(size, &(nana->rodata_relocation_list)) == false){
				return NANAFY_RODATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		default:
			return NANAFY_ERROR;
	}
}
