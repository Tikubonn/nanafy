#include <nanafy.h>
#include <stddef.h>

int read_nanafy_all_image_section_header_product (void *sequence, size_t size, size_t offset, nanafy *nana, size_t *readsizep){
	size_t off = offset;
	// *text
	{
		size_t si = sizeof_nanafy_image_section_header_product(NANAFY_TEXT_SECTION, nana);
		if (0 < si && off < si){
			return read_nanafy_image_section_header_product(sequence, size, off, NANAFY_TEXT_SECTION, nana, readsizep);
		}
		off -= si;
	}
	// *data
	{
		size_t si = sizeof_nanafy_image_section_header_product(NANAFY_DATA_SECTION, nana);
		if (0 < si && off < si){
			return read_nanafy_image_section_header_product(sequence, size, off, NANAFY_DATA_SECTION, nana, readsizep);
		}
		off -= si;
	}
	// *rodata
	{
		size_t si = sizeof_nanafy_image_section_header_product(NANAFY_RODATA_SECTION, nana);
		if (0 < si && off < si){
			return read_nanafy_image_section_header_product(sequence, size, off, NANAFY_RODATA_SECTION, nana, readsizep);
		}
		off -= si;
	}
	// *bss
	{
		size_t si = sizeof_nanafy_image_section_header_product(NANAFY_BSS_SECTION, nana);
		if (0 < si && off < si){
			return read_nanafy_image_section_header_product(sequence, size, off, NANAFY_BSS_SECTION, nana, readsizep);
		}
		off -= si;
	}
	// *eof
	*readsizep = 0;
	return 0;
}
