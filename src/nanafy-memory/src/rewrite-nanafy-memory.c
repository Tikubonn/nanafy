#include <nanafy.h>
#include <stddef.h>

int rewrite_nanafy_memory (void *sequence, size_t size, size_t index, nanafy_memory *memory){
	size_t buffsize = tell_nanafy_buffer(&(memory->buffer));
	if (index + size < buffsize){
		void *buffseq = nanafy_buffer_array(&(memory->buffer));
		for (size_t ind = 0; ind < size; ind++){
			((char*)buffseq)[index + ind] = ((char*)sequence)[ind];
		}
		return 0;
	}
	return 1;
}
