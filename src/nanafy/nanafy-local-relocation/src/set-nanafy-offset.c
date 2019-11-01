#include <nanafy.h>
#include <stddef.h>

int set_nanafy_offset (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana){
	switch (set_nanafy_offset_manually(section, offsetfrom, offsetto, size, nana)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_LOCAL_RELOCATION_LIST_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_local_relocation_list(1, &(nana->local_relocation_list)) != 0){
				return 1;
			}
			return set_nanafy_offset(section, offsetfrom, offsetto, size, nana);
		default:
			return 1;
	}
}
