#include <nanafy.h>
#include <stddef.h>

size_t tell_nanafy_buffer (nanafy_buffer *buffer){
	return buffer->seek;
}
