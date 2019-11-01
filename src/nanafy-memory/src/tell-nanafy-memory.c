#include <nanafy.h>
#include <stddef.h>

size_t tell_nanafy_memory (nanafy_memory *memory){
	return tell_nanafy_buffer(&(memory->buffer));
}
