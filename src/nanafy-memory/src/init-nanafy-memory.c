#include <nanafy.h>
#include <stddef.h>

void init_nanafy_memory (void *sequence, size_t size, nanafy_memory *memory){
	init_nanafy_buffer(sequence, size, &(memory->buffer));
}
