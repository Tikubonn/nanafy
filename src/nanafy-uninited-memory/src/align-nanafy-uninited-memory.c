#include <nanafy.h>
#include <stddef.h>

void align_nanafy_uninited_memory (size_t alignment, nanafy_uninited_memory *memory){
	memory->seek += alignment_padding_nanafy(alignment, memory->seek);
}
