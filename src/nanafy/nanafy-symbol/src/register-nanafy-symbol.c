#include <nanafy.h>
#include <stddef.h>

int register_nanafy_symbol (char *symname, size_t symnamesize, nanafy_section section, nanafy *nana, size_t *symidp){
	switch (register_nanafy_symbol_manually(symname, symnamesize, section, nana, symidp)){
		case NANAFY_SUCCESS:
			return 0;
		case NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_symname_table(0, 1, &(nana->symname_table)) != 0){
				return 1;
			}
			return register_nanafy_symbol(symname, symnamesize, section, nana, symidp);
		case NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_symname_table(symnamesize +1, 0, &(nana->symname_table)) != 0){
				return 1;
			}
			return register_nanafy_symbol(symname, symnamesize, section, nana, symidp);
		case NANAFY_SYMBOL_LIST_NOT_ENOUGH_MEMORY:
			if (extend_nanafy_symbol_list(1, &(nana->symbol_list)) != 0){
				return 1;
			}
			return register_nanafy_symbol(symname, symnamesize, section, nana, symidp);
		default:
			return 1;
	}
}
