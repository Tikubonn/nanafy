#include <nanafy.h>
#include <stddef.h>

size_t offsetof_nanafy_section_relocation_product (nanafy_section section, nanafy *nana){
	size_t offset = 0;
	switch (section){
		case NANAFY_RODATA_SECTION: 
			offset += sizeof_nanafy_section_relocation_product(NANAFY_DATA_SECTION, nana);
		case NANAFY_DATA_SECTION: 
			offset += sizeof_nanafy_section_relocation_product(NANAFY_TEXT_SECTION, nana);
		case NANAFY_TEXT_SECTION: 
			break;
		default:
			break;
	}
	return offset;
}
