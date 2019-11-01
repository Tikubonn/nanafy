#include <nanafy.h>
#include <stddef.h>

int remap_nanafy_text_memory (void *sequence, size_t size, nanafy *nana){
	nanafy_memory newmem;
	init_nanafy_memory(sequence, size, &newmem);
	if (copy_nanafy_memory(&(nana->text_memory), &newmem) != 0){
		return 1;
	}
	nana->text_memory = newmem;
	return 0;
}
