#include <nanafy.h>
#include <stddef.h>

void init_nanafy_buffer (void *sequence, size_t size, nanafy_buffer *buffer){
	buffer->sequence = sequence;
	buffer->seek = 0;
	buffer->size = size;
}
