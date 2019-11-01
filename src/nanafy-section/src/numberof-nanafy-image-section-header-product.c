#include <nanafy.h>
#include <stddef.h>

size_t numberof_nanafy_image_section_header_product (nanafy_section section){
	switch (section){
		case NANAFY_TEXT_SECTION:
			return 1;
		case NANAFY_DATA_SECTION:
			return 2;
		case NANAFY_RODATA_SECTION:
			return 3;
		case NANAFY_BSS_SECTION:
			return 4;
		default:
			return 0;
	}
}
