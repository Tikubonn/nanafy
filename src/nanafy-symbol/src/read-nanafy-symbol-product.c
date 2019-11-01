#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

int read_nanafy_symbol_product (void *sequence, size_t size, size_t offset, nanafy_symbol *symbol, nanafy *nana, size_t *readsizep){
	IMAGE_SYMBOL isymbol;
	if (setup_image_symbol_with_nanafy_symbol(symbol, nana, &isymbol) != 0){
		return 1;
	}
	size_t index;
	for (index = 0; index < size && offset + index < sizeof(isymbol); index++){
		((char*)sequence)[index] = 
			((char*)&isymbol)[offset + index];
	}
	*readsizep = index;
	return 0;
}
