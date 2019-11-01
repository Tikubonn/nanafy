#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_section_product (nanafy_section section, nanafy *nana){
	return nanafy_section_file_size(section, nana);
}
