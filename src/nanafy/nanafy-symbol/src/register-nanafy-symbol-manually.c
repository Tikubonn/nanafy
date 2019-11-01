#include <nanafy.h>
#include <stddef.h>

nanafy_status register_nanafy_symbol_manually (char *symname, size_t symnamesize, nanafy_section section, nanafy *nana, size_t *symidp){
	size_t symnameoffset;
	switch (add_nanafy_symname_table(symname, symnamesize, &(nana->symname_table), &symnameoffset)){
		case NANAFY_SUCCESS:
			break;
		case NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY:
			return NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY;
		case NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY:
			return NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY;
		case NANAFY_ERROR:
			return NANAFY_ERROR;
	}
	size_t offset;
	switch (section){
		case NANAFY_TEXT_SECTION:
			offset = tell_nanafy_memory(&(nana->text_memory));
			break;
		case NANAFY_DATA_SECTION:
			offset = tell_nanafy_memory(&(nana->data_memory));
			break;
		case NANAFY_RODATA_SECTION:
			offset = tell_nanafy_memory(&(nana->rodata_memory));
			break;
		case NANAFY_BSS_SECTION:
			offset = tell_nanafy_uninited_memory(&(nana->bss_memory));
			break;
		default:
			return NANAFY_ERROR;
	}
	nanafy_symbol symbol;
	init_nanafy_symbol(section, offset, symnameoffset, &symbol);
	if (add_nanafy_symbol_list(symbol, &(nana->symbol_list), symidp) != 0){
		return NANAFY_SYMBOL_LIST_NOT_ENOUGH_MEMORY;
	}
	return NANAFY_SUCCESS;
}
