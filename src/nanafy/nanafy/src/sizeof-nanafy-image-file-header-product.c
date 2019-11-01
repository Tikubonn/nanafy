#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

size_t sizeof_nanafy_image_file_header_product (nanafy *nana){
	(void)nana;
	return sizeof(IMAGE_FILE_HEADER);
}
