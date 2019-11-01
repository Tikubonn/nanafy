#include <nanafy.h>

int copy_nanafy_memory (nanafy_memory *memfrom, nanafy_memory *memto){
	return copy_nanafy_buffer(&(memfrom->buffer), &(memto->buffer));
}
