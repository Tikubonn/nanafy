#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

size_t sizeof_nanafy_image_section_header_product (nanafy_section section, nanafy *nana){
	(void)section;
	(void)nana;
	return sizeof(IMAGE_SECTION_HEADER);
}
