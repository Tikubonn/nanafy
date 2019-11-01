#include <nanafy.h>
#include <stddef.h>

nanafy_status put_nanafy_offset_manually (nanafy_section section, size_t offset, size_t size, nanafy *nana){
	switch (has_nanafy_section_margin(size, section, nana)){
		case NANAFY_SUCCESS:
			break;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY;
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY;
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY;
		case NANAFY_BSS_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_BSS_MEMORY_NOT_ENOUGH_MEMORY;
		default:
			return NANAFY_ERROR;
	}
	if (has_nanafy_local_relocation_list_margin(1, &(nana->local_relocation_list)) == false){
		return NANAFY_LOCAL_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
	}
	size_t offsetto = tell_nanafy_section(section, nana);
	if (allocate_nanafy_section(size, section, nana) != NANAFY_SUCCESS){
		return NANAFY_ERROR; // unknown status!
	}
	nanafy_local_relocation relocation;
	init_nanafy_local_relocation(section, offset, offsetto, size, &relocation);
	size_t index;
	if (add_nanafy_local_relocation_list(relocation, &(nana->local_relocation_list), &index) != 0){
		return NANAFY_ERROR; // unknown status!
	}
	return NANAFY_SUCCESS;
}
