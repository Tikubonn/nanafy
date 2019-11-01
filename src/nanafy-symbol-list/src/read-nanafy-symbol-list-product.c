#include <nanafy.h>
#include <stddef.h>

int read_nanafy_symbol_list_product (void *sequence, size_t size, size_t offset, nanafy_symbol_list *list, nanafy *nana, size_t *readsizep){
	size_t off = offset;
	size_t length = nanafy_symbol_list_length(list);
	for (size_t index = 0; index < length; index++){
		nanafy_symbol symbol;
		if (get_nanafy_symbol_list(index, list, &symbol) != 0){
			return 1;
		}
		size_t si = sizeof_nanafy_symbol_product(&symbol);
		if (0 < si && off < si){
			return read_nanafy_symbol_product(sequence, size, off, &symbol, nana, readsizep);
		}
		off -= si;
	}
	*readsizep = 0;
	return 0;
}
