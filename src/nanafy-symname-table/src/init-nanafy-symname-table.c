#include <nanafy.h>
#include <stddef.h>

void init_nanafy_symname_table (
	void *buffseq,
	size_t buffsize, 
	size_t *arrayseq,
	size_t arraysize,
	nanafy_symname_table_hash_func hashfunc,
	nanafy_symname_table *table){
	init_nanafy_size_array(arrayseq, arraysize, &(table->array));
	init_nanafy_buffer(buffseq, buffsize, &(table->buffer));
	clear_nanafy_size_array(NANAFY_SYMNAME_TABLE_EMPTY, &(table->array)); // clear!
	table->hashfunc = hashfunc;
}
