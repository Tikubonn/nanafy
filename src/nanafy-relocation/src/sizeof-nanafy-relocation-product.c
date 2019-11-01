#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

size_t sizeof_nanafy_relocation_product (nanafy_section section, nanafy_relocation *relocation){
	(void)relocation;
	return sizeof(IMAGE_RELOCATION);
}
