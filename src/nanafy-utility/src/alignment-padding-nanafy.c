#include <stddef.h>

size_t alignment_padding_nanafy (size_t alignment, size_t offset){
	return 
		(offset < alignment) ? 
		(alignment - offset) : 
		(offset % alignment == 0) ? 0 :
			(alignment - offset % alignment);
}
