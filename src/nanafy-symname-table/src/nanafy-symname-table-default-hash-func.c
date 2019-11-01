#include <stddef.h>

size_t NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC (char *sequence, size_t size){
	size_t hashnum = 0;
	for (size_t index = 0; index < size; index++){
		hashnum += sequence[index];
	}
	return hashnum;
}
