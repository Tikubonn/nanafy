#include <nanafy.h>
#include <stddef.h>

int fix_nanafy_memory_with_local_relocation_list (nanafy_local_relocation_list *list, nanafy *nana){
	size_t length = nanafy_local_relocation_list_length(list);
	for (size_t index = 0; index < length; index++){
		nanafy_local_relocation relocation;
		if (get_nanafy_local_relocation_list(index, list, &relocation) != 0){
			return 1;
		}
		if (fix_nanafy_memory_with_local_relocation(&relocation, nana) != 0){
			return 1;
		}
	}
	return 0;
}
