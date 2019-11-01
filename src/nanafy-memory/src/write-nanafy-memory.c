#include <nanafy.h>
#include <stddef.h>

int write_nanafy_memory (void *sequence, size_t size, nanafy_memory *memory){
	if (has_nanafy_buffer_margin(size, &(memory->buffer)) == true){
		size_t wrotesize;
		write_nanafy_buffer(sequence, size, &(memory->buffer), &wrotesize);
		return 0;
	}
	return 1;
}
