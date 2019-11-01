#include <nanafy.h>
#include <stddef.h>

int put_nanafy_offset (nanafy_section section, size_t offset, size_t size, nanafy *nana){
	switch (put_nanafy_offset_manually(section, offset, size, nana)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(1, &(nana->text_memory)) != 0){
				return 1;
			}
			return put_nanafy_offset(section, offset, size, nana);
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(1, &(nana->data_memory)) != 0){
				return 1;
			}
			return put_nanafy_offset(section, offset, size, nana);
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(1, &(nana->rodata_memory)) != 0){
				return 1;
			}
			return put_nanafy_offset(section, offset, size, nana);
		case NANAFY_LOCAL_RELOCATION_LIST_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_local_relocation_list(1, &(nana->local_relocation_list)) != 0){
				return 1;
			}
			return put_nanafy_offset(section, offset, size, nana);
		default:
			return 1;
	}
}
