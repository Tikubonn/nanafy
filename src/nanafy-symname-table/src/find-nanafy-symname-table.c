#include <nanafy.h>
#include <stddef.h>

int find_nanafy_symname_table (char *symname, size_t symnamesize, nanafy_symname_table *table, bool *foundp, size_t *offsetp){
	size_t hashed = table->hashfunc(symname, symnamesize);
	size_t size = nanafy_size_array_length(&(table->array));
	for (size_t index = 0; index < size; index++){
		size_t ind = (hashed + index) % size;
		size_t offset;
		if (get_nanafy_size_array(ind, &(table->array), &offset) != 0){
			return 1;
		}
		if (offset == NANAFY_SYMNAME_TABLE_EMPTY){
			*foundp = false;
			return 0;
		}
		else {
			char *sname = nanafy_buffer_array(&(table->buffer)) + offset;
			size_t snamesize = strlen_nanafy(sname);
			if (strcmp_nanafy(sname, snamesize, symname, symnamesize) == true){
				*foundp = true;
				*offsetp = offset;
				return 0;
			}
		}
	}
	*foundp = false;
	return 0;
}
