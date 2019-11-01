#include <nanafy.h>
#include <stddef.h>

int read_nanafy_image_file_header_product (void *sequence, size_t size, size_t offset, nanafy *nana, size_t *readsizep){
	IMAGE_FILE_HEADER ifheader;
	if (setup_image_file_header_with_nanafy(nana, &ifheader) != 0){
		return 1;
	}
	size_t index;
	for (index = 0; index < size && offset + index < sizeof(ifheader); index++){
		((char*)sequence)[index] = ((char*)&ifheader)[offset + index];
	}
	*readsizep = index;
	return 0;
}
