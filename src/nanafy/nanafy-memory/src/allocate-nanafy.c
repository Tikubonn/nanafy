#include <nanafy.h>
#include <stddef.h>

int allocate_nanafy (size_t size, nanafy_section section, nanafy *nana){
	switch (allocate_nanafy_manually(size, section, nana)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(size, &(nana->text_memory)) != 0){
				return 1;
			}
			return allocate_nanafy(size, section, nana);
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(size, &(nana->data_memory)) != 0){
				return 1;
			}
			return allocate_nanafy(size, section, nana);
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(size, &(nana->rodata_memory)) != 0){
				return 1;
			}
			return allocate_nanafy(size, section, nana);
		default:
			return 1;
	}
}
