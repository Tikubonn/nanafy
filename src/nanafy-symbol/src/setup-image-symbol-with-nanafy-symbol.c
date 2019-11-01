#include <nanafy.h>
#include <stdbool.h>
#include <windows.h>

int setup_image_symbol_with_nanafy_symbol (nanafy_symbol *symbol, nanafy *nana, IMAGE_SYMBOL *isymbol){
	isymbol->N.Name.Short = 0;
	isymbol->N.Name.Long = symbol->symnameoffset +4; // after symname table size!
	if (symbol->type == NANAFY_EXTERNAL_SYMBOL){
		isymbol->Value = 0;
		isymbol->SectionNumber = 0;
	}
	else {
		isymbol->Value = symbol->offset; 
		isymbol->SectionNumber = 
			numberof_nanafy_image_section_header_product(symbol->section);
	}
	isymbol->Type = IMAGE_SYM_TYPE_NULL;
	switch (symbol->type){
		case NANAFY_PUBLIC_SYMBOL:
			isymbol->StorageClass = IMAGE_SYM_CLASS_EXTERNAL;
			break;
		case NANAFY_EXTERNAL_SYMBOL:
			isymbol->StorageClass = IMAGE_SYM_CLASS_EXTERNAL;
			break;
		case NANAFY_PRIVATE_SYMBOL:
			isymbol->StorageClass = IMAGE_SYM_CLASS_STATIC;
			break;
		default:
			return 1;
	}
	isymbol->NumberOfAuxSymbols = 0;
	return 0;
}
