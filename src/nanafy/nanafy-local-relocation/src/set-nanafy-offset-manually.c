#include <nanafy.h>
#include <stddef.h>

nanafy_status set_nanafy_offset_manually (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana){
	size_t offset = tell_nanafy_section(section, nana);
	if (offsetto < offset){
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(section, offsetfrom, offsetto, size, &relocation);
		bool found;
		size_t foundindex;
		if (find_nanafy_local_relocation_list(&relocation, &(nana->local_relocation_list), &found, &foundindex) != 0){
			return NANAFY_ERROR;
		}
		if (found == true){
			if (set_nanafy_local_relocation_list(relocation, foundindex, &(nana->local_relocation_list)) != 0){
				return NANAFY_ERROR;
			}
			return NANAFY_SUCCESS;
		}
		else {
			size_t index;
			if (add_nanafy_local_relocation_list(relocation, &(nana->local_relocation_list), &index) != 0){
				return NANAFY_LOCAL_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		}
	}
	return NANAFY_ERROR; // offsetto is overflow!
}
