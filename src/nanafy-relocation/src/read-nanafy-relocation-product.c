#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

int read_nanafy_relocation_product (void *sequence, size_t size, size_t offset, nanafy_section section, nanafy_relocation *relocation, nanafy *nana, size_t *readsizep){
	IMAGE_RELOCATION irelocation;
	if (setup_image_relocation_with_nanafy_relocation(section, relocation, nana, &irelocation) != 0){
		return 1;
	}
	size_t index;
	for (index = 0; offset + index < sizeof(irelocation); index++){
		((char*)sequence)[index] = 
			((char*)&irelocation)[offset + index];
	}
	*readsizep = index;
	return 0;
}
