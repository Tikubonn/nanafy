#include <nanafy.h>
#include <stddef.h>

nanafy_status allocate_nanafy_manually (size_t size, nanafy_section section, nanafy *nana){
	return allocate_nanafy_section(size, section, nana);
}
