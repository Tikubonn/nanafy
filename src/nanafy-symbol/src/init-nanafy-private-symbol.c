#include <nanafy.h>
#include <stddef.h>
#include <stdbool.h>

void init_nanafy_private_symbol (nanafy_section section, size_t offset, size_t symnameoffset, nanafy_symbol *symbol){
	symbol->type = NANAFY_PRIVATE_SYMBOL;
	symbol->section = section;
	symbol->offset = offset;
	symbol->symnameoffset = symnameoffset;
}
