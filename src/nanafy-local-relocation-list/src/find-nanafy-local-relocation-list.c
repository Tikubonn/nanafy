#include <nanafy.h>
#include <stddef.h>

int find_nanafy_local_relocation_list (nanafy_local_relocation *relocation, nanafy_local_relocation_list *list, bool *foundp, size_t *indexp){
	size_t length = nanafy_local_relocation_list_length(list);
	for (size_t index = 0; index < length; index++){
		nanafy_local_relocation reloc;
		if (get_nanafy_local_relocation_list(index, list, &reloc) != 0){
			return 1;
		}
		if (same_nanafy_local_relocation_placep(&reloc, relocation) == true){
			*foundp = true;
			*indexp = index;
			return 0;
		}
	}
	*foundp = false;
	return 0;
}
