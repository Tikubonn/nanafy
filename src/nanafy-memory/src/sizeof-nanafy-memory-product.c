#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_memory_product (nanafy_memory *memory){
	return tell_nanafy_buffer(&(memory->buffer));
}
