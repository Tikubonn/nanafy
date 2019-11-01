#include <nanafy.h>
#include <stddef.h>

nanafy_status allocate (size_t size, nanafy_section section, nanafy *nana){
	switch (has_nanafy_section_margin(size, section, nana)){
		case NANAFY_SUCCESS:
			break;
		case NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY;
		case NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY;
		case NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY:
			return NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY;
		default:
			return NANAFY_ERROR;
	}
	for (size_t count = 0; count < size; count++){
		if (put_nanafy_section(0, section, nana) != NANAFY_SUCCESS){
			return NANAFY_ERROR;
		}
	}
	return NANAFY_SUCCESS;
}

nanafy_status allocate_nanafy_section (size_t size, nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			return allocate(size, section, nana);
		case NANAFY_DATA_SECTION: 
			return allocate(size, section, nana);
		case NANAFY_RODATA_SECTION: 
			return allocate(size, section, nana);
		case NANAFY_BSS_SECTION:
			allocate_nanafy_uninited_memory(size, &(nana->bss_memory));
			return NANAFY_SUCCESS;
		default:
			return NANAFY_ERROR;
	}
}
