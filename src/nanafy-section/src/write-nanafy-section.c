#include <nanafy.h>
#include <stddef.h>

nanafy_status write_nanafy_section (void *sequence, size_t size, nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			if (write_nanafy_memory(sequence, size, &(nana->text_memory)) != 0){
				return NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_DATA_SECTION: 
			if (write_nanafy_memory(sequence, size, &(nana->data_memory)) != 0){
				return NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		case NANAFY_RODATA_SECTION: 
			if (write_nanafy_memory(sequence, size, &(nana->rodata_memory)) != 0){
				return NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		default:
			return NANAFY_ERROR;
	}
}
