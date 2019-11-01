#include <nanafy.h>
#include <stddef.h>

size_t tell_nanafy_section (nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION:
			return tell_nanafy_memory(&(nana->text_memory));
		case NANAFY_DATA_SECTION:
			return tell_nanafy_memory(&(nana->data_memory));
		case NANAFY_RODATA_SECTION:
			return tell_nanafy_memory(&(nana->rodata_memory));
		case NANAFY_BSS_SECTION:
			return tell_nanafy_uninited_memory(&(nana->bss_memory));
		default:
			return 0;
	}
}
