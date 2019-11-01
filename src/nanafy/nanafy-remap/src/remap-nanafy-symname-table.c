#include <nanafy.h>
#include <stddef.h>

int remap_nanafy_symname_table (void *buffseq, size_t buffsize, size_t *arrayseq, size_t arraysize, nanafy *nana){
	nanafy_symname_table newtable;
	init_nanafy_symname_table(buffseq, buffsize, arrayseq, arraysize, nana->symname_table.hashfunc, &newtable);
	if (copy_nanafy_symname_table(&(nana->symname_table), &newtable) != 0){
		return 1;
	}
	nana->symname_table = newtable;
	return 0;
}
