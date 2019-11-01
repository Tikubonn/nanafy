#include <nanafy.h>
#include <stddef.h>
#include <stdbool.h>

bool has_nanafy_memory_margin (size_t size, nanafy_memory *memory){
	return has_nanafy_buffer_margin(size, &(memory->buffer));
}
