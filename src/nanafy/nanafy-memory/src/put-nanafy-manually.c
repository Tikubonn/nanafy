#include <nanafy.h>
#include <stddef.h>

int put_nanafy_manually (int value, nanafy_section section, nanafy *nana){
	return put_nanafy_section(value, section, nana);
}
