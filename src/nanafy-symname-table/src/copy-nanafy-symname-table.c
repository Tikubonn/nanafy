#include <nanafy.h>
#include <stddef.h>

static int insert (size_t offset, nanafy_symname_table *table){
	char *symname = nanafy_buffer_array(&(table->buffer)) + offset;
	size_t symnamesize = strlen_nanafy(symname);
	size_t hashed = table->hashfunc(symname, symnamesize);
	size_t size = nanafy_size_array_length(&(table->array));
	for (size_t index = 0; index < size; index++){
		size_t ind = (hashed + index) % size;
		size_t off;
		if (get_nanafy_size_array(ind, &(table->array), &off) != 0){
			return 1;
		}
		if (off == NANAFY_SYMNAME_TABLE_EMPTY){
			if (set_nanafy_size_array(offset, ind, &(table->array)) != 0){
				return 1;
			}
			return 0; // inserted!
		}
		else {
			char *sname = nanafy_buffer_array(&(table->buffer)) + off;
			size_t snamesize = strlen_nanafy(sname);
			if (strcmp_nanafy(sname, snamesize, symname, symnamesize) == true){
				return 0; // already inserted!
			}
		}
	}
	return 1;
}

int copy_nanafy_symname_table (nanafy_symname_table *tablefrom, nanafy_symname_table *tableto){
	if (copy_nanafy_buffer(&(tablefrom->buffer), &(tableto->buffer)) != 0){
		return 1;
	}
	clear_nanafy_size_array(NANAFY_SYMNAME_TABLE_EMPTY, &(tableto->array));
	size_t size = nanafy_size_array_length(&(tablefrom->array));
	for (size_t index = 0; index < size; index++){
		size_t offsetfrom;
		if (get_nanafy_size_array(index, &(tablefrom->array), &offsetfrom) != 0){
			return 1;
		}
		if (offsetfrom != NANAFY_SYMNAME_TABLE_EMPTY){
			if (insert(offsetfrom, tableto) != 0){
				return 1;
			}
		}
	}
	return 0;
}
