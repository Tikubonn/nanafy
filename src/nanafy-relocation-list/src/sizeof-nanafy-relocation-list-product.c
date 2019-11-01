#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_relocation_list_product (nanafy_section section, nanafy_relocation_list *list){
	size_t count = 0;
	for (size_t index = 0; index < nanafy_relocation_list_length(list); index++){
		nanafy_relocation relocation;
		if (get_nanafy_relocation_list(index, list, &relocation) != 0){
			break; // skip!
		}
		count += sizeof_nanafy_relocation_product(section, &relocation);
	}
	return count;
}
