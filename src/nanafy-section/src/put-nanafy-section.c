#include <nanafy.h>
#include <stddef.h>

nanafy_status put_nanafy_section (int value, nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			if (put_nanafy_memory(value, &(nana->text_memory)) != 0){
				return NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_DATA_SECTION: 
			if (put_nanafy_memory(value, &(nana->data_memory)) != 0){
				return NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_RODATA_SECTION: 
			if (put_nanafy_memory(value, &(nana->rodata_memory)) != 0){
				return NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		default:
			return NANAFY_ERROR;
	}
}
