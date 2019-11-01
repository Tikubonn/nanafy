#include <nanafy.h>
#include <stddef.h>

int set_nanafy_memory (int value, size_t index, nanafy_memory *memory){
	size_t buffsize = tell_nanafy_buffer(&(memory->buffer));
	if (index < buffsize){
		void *buffseq = nanafy_buffer_array(&(memory->buffer));
		((char*)buffseq)[index] = value;
		return 0;
	}
	return 1;
}
