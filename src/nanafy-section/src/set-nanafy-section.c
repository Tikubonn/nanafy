#include <nanafy.h>
#include <stddef.h>

int set_nanafy_section (int value, nanafy_section section, size_t index, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: 
			return set_nanafy_memory(value, index, &(nana->text_memory));
		case NANAFY_DATA_SECTION: 
			return set_nanafy_memory(value, index, &(nana->data_memory));
		case NANAFY_RODATA_SECTION: 
			return set_nanafy_memory(value, index, &(nana->rodata_memory));
		default:
			return 1;
	}
}
