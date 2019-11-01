#include <nanafy.h>
#include <stddef.h>

int remap_nanafy_text_relocation_list (nanafy_relocation *sequence, size_t size, nanafy *nana){
	nanafy_relocation_list newmem;
	init_nanafy_relocation_list(sequence, size, &newmem);
	if (copy_nanafy_relocation_list(&(nana->text_relocation_list), &newmem) != 0){
		return 1;
	}
	nana->text_relocation_list = newmem;
	return 0;
}
