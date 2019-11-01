#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

int read_nanafy_image_section_header_product (void *sequence, size_t size, size_t offset, nanafy_section section, nanafy *nana, size_t *readsizep){
	if (0 < sizeof_nanafy_image_section_header_product(section, nana)){
		IMAGE_SECTION_HEADER isheader;
		if (setup_image_section_header_with_nanafy_section(section, nana, &isheader) != 0){
			return 1;
		}
		size_t index;
		for (index = 0; index < size && offset + index < sizeof(isheader); index++){
			((char*)sequence)[index] = ((char*)&isheader)[offset + index];
		}
		*readsizep = index;
		return 0;
	}
	*readsizep = 0;
	return 0;
}
