#include <nanafy.h>
#include <stddef.h>

int put_nanafy_external_relative_offset (size_t symid, nanafy_section section, size_t size, nanafy *nana){
	switch (put_nanafy_external_relative_offset_manually(symid, section, size, nana)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(size, &(nana->text_memory)) != 0){
				return 1;
			}
			return put_nanafy_external_relative_offset(symid, section, size, nana);
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(size, &(nana->data_memory)) != 0){
				return 1;
			}
			return put_nanafy_external_relative_offset(symid, section, size, nana);
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_memory(size, &(nana->rodata_memory)) != 0){
				return 1;
			}
			return put_nanafy_external_relative_offset(symid, section, size, nana);
		case NANAFY_TEXT_RELOCATION_LIST_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_relocation_list(1, &(nana->text_relocation_list)) != 0){
				return 1;
			}
			return put_nanafy_external_relative_offset(symid, section, size, nana);
		case NANAFY_DATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_relocation_list(1, &(nana->data_relocation_list)) != 0){
				return 1;
			}
			return put_nanafy_external_relative_offset(symid, section, size, nana);
		case NANAFY_RODATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_relocation_list(1, &(nana->rodata_relocation_list)) != 0){
				return 1;
			}
			return put_nanafy_external_relative_offset(symid, section, size, nana);
		default:
			return 1;
	}
}
