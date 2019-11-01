#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_all_image_section_header_product (nanafy *nana){
	return 
		sizeof_nanafy_image_section_header_product(NANAFY_TEXT_SECTION, nana) + 
		sizeof_nanafy_image_section_header_product(NANAFY_DATA_SECTION, nana) + 
		sizeof_nanafy_image_section_header_product(NANAFY_RODATA_SECTION, nana) + 
		sizeof_nanafy_image_section_header_product(NANAFY_BSS_SECTION, nana);
}
