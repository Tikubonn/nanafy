#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

size_t sizeof_nanafy_symbol_product (nanafy_symbol *symbol){
	(void)symbol;
	return sizeof(IMAGE_SYMBOL);
}
