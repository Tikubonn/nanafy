#include <nanafy.h>
#include <stddef.h>
#include <stdbool.h>

void init_nanafy_external_symbol (size_t symnameoffset, nanafy_symbol *symbol){
	symbol->type = NANAFY_EXTERNAL_SYMBOL;
	symbol->section = NANAFY_NONE_SECTION;
	symbol->offset = 0;
	symbol->symnameoffset = symnameoffset;
}
