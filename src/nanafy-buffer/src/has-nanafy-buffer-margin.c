#include <nanafy.h>
#include <stddef.h>
#include <stdbool.h>

bool has_nanafy_buffer_margin (size_t size, nanafy_buffer *buffer){
	return buffer->seek + size <= buffer->size;
}
