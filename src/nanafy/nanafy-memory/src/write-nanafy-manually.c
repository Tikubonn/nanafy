#include <nanafy.h>
#include <stddef.h>

nanafy_status write_nanafy_manually (void *sequence, size_t size, nanafy_section section, nanafy *nana){
	return write_nanafy_section(sequence, size, section, nana);
}
