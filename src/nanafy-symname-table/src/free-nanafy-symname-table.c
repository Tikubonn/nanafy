#include <nanafy.h>

void free_nanafy_symname_table (nanafy_symname_table *table){
	free_nanafy_size_array(&(table->array));
	free_nanafy_buffer(&(table->buffer));
}
