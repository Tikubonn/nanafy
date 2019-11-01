#include <nanafy.h>
#include <stddef.h>
#define min(a, b) ((a)<(b)?(a):(b))

int read_nanafy_memory_product (void *sequence, size_t size, size_t offset, nanafy_memory *memory, size_t *readsizep){
	size_t buffsize = tell_nanafy_buffer(&(memory->buffer));
	void *buffseq = nanafy_buffer_array(&(memory->buffer));
	size_t index;
	for (index = 0; index < size && offset + index < buffsize; index++){
		((char*)sequence)[index] = ((char*)buffseq)[offset + index];
	}
	*readsizep = index;
	return 0;
}
