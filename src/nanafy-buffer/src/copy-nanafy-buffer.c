#include <nanafy.h>
#include <stddef.h>

int copy_nanafy_buffer (nanafy_buffer *bufferfrom, nanafy_buffer *bufferto){
	if (bufferfrom->seek <= bufferto->size){
		for (size_t index = 0; index < bufferfrom->seek; index++){
			((char*)(bufferto->sequence))[index] = 
				((char*)(bufferfrom->sequence))[index];
		}
		bufferto->seek = bufferfrom->seek;
		return 0;
	}
	return 1;
}
