#include <nanafy.h>
#include <stddef.h>

nanafy_status align_nanafy_manually (int value, size_t alignment, nanafy_section section, nanafy *nana){
	return align_nanafy_section(value, alignment, section, nana);
}
