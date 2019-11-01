#include <nanafy.h>
#include <stddef.h>

int remap_nanafy_symbol_list (nanafy_symbol *sequence, size_t size, nanafy *nana){
	nanafy_symbol_list newmem;
	init_nanafy_symbol_list(sequence, size, &newmem);
	if (copy_nanafy_symbol_list(&(nana->symbol_list), &newmem) != 0){
		return 1;
	}
	nana->symbol_list = newmem;
	return 0;
}
