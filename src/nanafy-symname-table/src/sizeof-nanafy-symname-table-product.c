#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_symname_table_product (nanafy_symname_table *table){
	return tell_nanafy_buffer(&(table->buffer)) +4;
	//return tell_nanafy_buffer(&(table->buffer));
}
