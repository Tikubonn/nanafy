#include <nanafy.h>
#include <stddef.h>

int align_nanafy_memory (int value, size_t alignment, nanafy_memory *memory){
	size_t size = alignment_padding_nanafy(alignment, tell_nanafy_buffer(&(memory->buffer)));
	if (has_nanafy_buffer_margin(size, &(memory->buffer)) == true){
		for (size_t count = 0; count < size; count++){
			if (put_nanafy_buffer(value, &(memory->buffer)) != 0){
				return 1;
			}
		}
		return 0;
	}
	return 1;
}
