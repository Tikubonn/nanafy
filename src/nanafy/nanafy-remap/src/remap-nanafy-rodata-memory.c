#include <nanafy.h>
#include <stddef.h>

int remap_nanafy_rodata_memory (void *sequence, size_t size, nanafy *nana){
	nanafy_memory newmem;
	init_nanafy_memory(sequence, size, &newmem);
	if (copy_nanafy_memory(&(nana->rodata_memory), &newmem) != 0){
		return 1;
	}
	nana->rodata_memory = newmem;
	return 0;
}
