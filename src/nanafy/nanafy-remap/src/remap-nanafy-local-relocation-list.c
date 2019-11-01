#include <nanafy.h>
#include <stddef.h>

int remap_nanafy_local_relocation_list (nanafy_local_relocation *sequence, size_t size, nanafy *nana){
	nanafy_local_relocation_list newmem;
	init_nanafy_local_relocation_list(sequence, size, &newmem);
	if (copy_nanafy_local_relocation_list(&(nana->local_relocation_list), &newmem) != 0){
		return 1;
	}
	nana->local_relocation_list = newmem;
	return 0;
}
