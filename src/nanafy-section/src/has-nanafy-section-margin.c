#include <nanafy.h>
#include <stddef.h>

nanafy_status has_nanafy_section_margin (size_t size, nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			if (has_nanafy_memory_margin(size, &(nana->text_memory)) == false){
				return NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_DATA_SECTION: 
			if (has_nanafy_memory_margin(size, &(nana->data_memory)) == false){
				return NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_RODATA_SECTION: 
			if (has_nanafy_memory_margin(size, &(nana->rodata_memory)) == false){
				return NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_BSS_SECTION:
			return NANAFY_SUCCESS;
		default:
			return NANAFY_ERROR;
	}
}
