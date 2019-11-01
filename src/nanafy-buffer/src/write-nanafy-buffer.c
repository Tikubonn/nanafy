#include <nanafy.h>
#include <stddef.h>
#define min(a, b) ((a)<(b)?(a):(b))

void write_nanafy_buffer (void *sequence, size_t size, nanafy_buffer *buffer, size_t *wrotesizep){
	size_t si = min(size, buffer->size - buffer->seek);
	for (size_t index = 0; index < si; index++){
		((char*)(buffer->sequence))[buffer->seek + index] = 
			((char*)(sequence))[index];
	}
	buffer->seek += si;
	*wrotesizep = si;
}
