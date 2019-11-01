#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_all_section_relocation_product (nanafy *nana){
	return 
		sizeof_nanafy_section_relocation_product(NANAFY_TEXT_SECTION, nana) +
		sizeof_nanafy_section_relocation_product(NANAFY_DATA_SECTION, nana) + 
		sizeof_nanafy_section_relocation_product(NANAFY_RODATA_SECTION, nana);
}
