#include <nanafy.h>
#include <stddef.h>

int extend_nanafy_memory (size_t exsize, nanafy_memory *memory){
	return extend_nanafy_buffer(exsize, &(memory->buffer));
}
