#include <nanafy.h>
#include <stddef.h>

int align_nanafy (int value, size_t alignment, nanafy_section section, nanafy *nana){
	switch (align_nanafy_manually(value, alignment, section, nana)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY: 
			if (extend_nanafy_memory(alignment, &(nana->text_memory)) != 0){
				return 1;
			}
			return align_nanafy(value, alignment, section, nana);
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY: 
			if (extend_nanafy_memory(alignment, &(nana->data_memory)) != 0){
				return 1;
			}
			return align_nanafy(value, alignment, section, nana);
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY: 
			if (extend_nanafy_memory(alignment, &(nana->rodata_memory)) != 0){
				return 1;
			}
			return align_nanafy(value, alignment, section, nana);
		default:
			return 1;
	}
}
