#include <nanafy.h>
#include <stddef.h>

int put_nanafy_buffer (int value, nanafy_buffer *buffer){
	if (buffer->seek < buffer->size){
		((char*)(buffer->sequence))[buffer->seek] = value;
		buffer->seek += 1;
		return 0;
	}
	return 1;
}
