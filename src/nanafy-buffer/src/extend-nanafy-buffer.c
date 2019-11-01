#include <nanafy.h>
#include <stddef.h>

int extend_nanafy_buffer (size_t exsize, nanafy_buffer *buffer){
	size_t newsize = buffer->size + exsize;
	void *newseq = realloc(buffer->sequence, newsize);
	if (newseq == NULL){
		return 1;
	}
	else {
		buffer->sequence = newseq;
		buffer->size = newsize;
		return 0;
	}
}
