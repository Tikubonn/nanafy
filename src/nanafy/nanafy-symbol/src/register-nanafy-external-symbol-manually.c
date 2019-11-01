#include <nanafy.h>
#include <stddef.h>

nanafy_status register_nanafy_external_symbol_manually (char *symname, size_t symnamesize, nanafy *nana, size_t *symidp){
	size_t symnameoffset;
	switch (add_nanafy_symname_table(symname, symnamesize, &(nana->symname_table), &symnameoffset)){
		case NANAFY_SUCCESS:
			break;
		case NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY:
			return NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY;
		case NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY:
			return NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY;
		default:
			return NANAFY_ERROR;
	}
	nanafy_symbol symbol;
	init_nanafy_external_symbol(symnameoffset, &symbol);
	if (add_nanafy_symbol_list(symbol, &(nana->symbol_list), symidp) != 0){
		return NANAFY_SYMBOL_LIST_NOT_ENOUGH_MEMORY;
	}
	return NANAFY_SUCCESS;
}
