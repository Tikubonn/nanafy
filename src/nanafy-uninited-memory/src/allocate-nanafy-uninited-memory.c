#include <nanafy.h>
#include <stddef.h>

void allocate_nanafy_uninited_memory (size_t size, nanafy_uninited_memory *memory){
	memory->seek += size;
}
