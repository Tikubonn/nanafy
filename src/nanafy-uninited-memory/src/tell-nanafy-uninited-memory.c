#include <nanafy.h>
#include <stddef.h>

size_t tell_nanafy_uninited_memory (nanafy_uninited_memory *memory){
	return memory->seek;
}
