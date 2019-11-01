#include <nanafy.h>
#include <stddef.h>

size_t sizeof_nanafy_symbol_list_product (nanafy_symbol_list *list){
	size_t count = 0;
	for (size_t index = 0; index < nanafy_symbol_list_length(list); index++){
		nanafy_symbol symbol;
		if (get_nanafy_symbol_list(index, list, &symbol) != 0){
			break; // skip!
		}
		count += sizeof_nanafy_symbol_product(&symbol);
	}
	return count;
}
