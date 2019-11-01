#include <nanafy.h>
#include <stddef.h>

int put_nanafy_memory (int value, nanafy_memory *memory){
	return put_nanafy_buffer(value, &(memory->buffer));
}
