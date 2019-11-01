#include <nanafy.h>
#include <stddef.h>

int put_nanafy (int value, nanafy_section section, nanafy *nana){
	switch (put_nanafy_manually(value, section, nana)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY: 
			if (extend_nanafy_memory(1, &(nana->text_memory)) != 0){
				return 1;
			}
			return put_nanafy(value, section, nana);
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY: 
			if (extend_nanafy_memory(1, &(nana->data_memory)) != 0){
				return 1;
			}
			return put_nanafy(value, section, nana);
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY: 
			if (extend_nanafy_memory(1, &(nana->rodata_memory)) != 0){
				return 1;
			}
			return put_nanafy(value, section, nana);
		default:
			return NANAFY_ERROR;
	}
}
