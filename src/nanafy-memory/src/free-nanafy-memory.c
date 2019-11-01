#include <nanafy.h>

void free_nanafy_memory (nanafy_memory *memory){
	free_nanafy_buffer(&(memory->buffer));
}
