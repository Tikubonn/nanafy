#include <nanafy.h>
#include <stddef.h>

nanafy_status align_nanafy_section (int value, size_t alignment, nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			if (align_nanafy_memory(value, alignment, &(nana->text_memory)) != 0){
				return NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_DATA_SECTION: 
			if (align_nanafy_memory(value, alignment, &(nana->data_memory)) != 0){
				return NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_RODATA_SECTION: 
			if (align_nanafy_memory(value, alignment, &(nana->rodata_memory)) != 0){
				return NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_BSS_SECTION: 
			align_nanafy_uninited_memory(alignment, &(nana->bss_memory));
			return NANAFY_SUCCESS;
		default:
			return NANAFY_ERROR;
	}
}
