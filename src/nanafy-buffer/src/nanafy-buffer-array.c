#include <nanafy.h>

void *nanafy_buffer_array (nanafy_buffer *buffer){
	return buffer->sequence;
}
