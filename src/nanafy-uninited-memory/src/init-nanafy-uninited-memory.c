#include <nanafy.h>
#include <stddef.h>

void init_nanafy_uninited_memory (nanafy_uninited_memory *memory){
	memory->seek = 0;
}
