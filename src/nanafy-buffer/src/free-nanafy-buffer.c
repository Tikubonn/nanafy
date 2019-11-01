#include <nanafy.h>
#include <stdlib.h>

void free_nanafy_buffer (nanafy_buffer *buffer){
	if (buffer->sequence != NULL){
		free(buffer->sequence);
	}
}
