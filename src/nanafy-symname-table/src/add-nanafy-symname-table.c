#include <nanafy.h>
#include <stddef.h>

nanafy_status add_nanafy_symname_table (char *symname, size_t symnamesize, nanafy_symname_table *table, size_t *offsetp){
	if (has_nanafy_buffer_margin(symnamesize +1, &(table->buffer)) == true){
		size_t hashed = table->hashfunc(symname, symnamesize);
		size_t size = nanafy_size_array_length(&(table->array));
		for (size_t index = 0; index < size; index++){
			size_t ind = (hashed + index) % size;
			size_t offset;
			if (get_nanafy_size_array(ind, &(table->array), &offset) != 0){
				return NANAFY_ERROR;
			}
			if (offset == NANAFY_SYMNAME_TABLE_EMPTY){
				size_t newoffset = tell_nanafy_buffer(&(table->buffer));
				size_t wrotesize;
				write_nanafy_buffer(symname, symnamesize, &(table->buffer), &wrotesize);
				if (put_nanafy_buffer('\0', &(table->buffer)) != 0){
					return NANAFY_ERROR;
				}
				if (set_nanafy_size_array(newoffset, ind, &(table->array)) != 0){
					return NANAFY_ERROR;
				}
				*offsetp = newoffset;
				return NANAFY_SUCCESS;
			}
			else {
				char *sname = nanafy_buffer_array(&(table->buffer)) + offset;
				size_t snamesize = strlen_nanafy(sname);
				if (strcmp_nanafy(sname, snamesize, symname, symnamesize) == true){
					*offsetp = offset;
					return NANAFY_SUCCESS;
				}
			}
		}
		return NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY;
	}
	return NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY;
}
