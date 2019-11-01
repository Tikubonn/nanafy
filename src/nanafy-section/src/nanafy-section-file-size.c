#include <nanafy.h>
#include <stddef.h>

/*
	text => data => rodata => bss 
	ファイルに展開された際の大きさを返します。
*/

size_t nanafy_section_file_size (nanafy_section section, nanafy *nana){
	switch (section){
		case NANAFY_BSS_SECTION: 
			return 0;
		case NANAFY_RODATA_SECTION: 
			return tell_nanafy_memory(&(nana->rodata_memory));
		case NANAFY_DATA_SECTION: 
			return tell_nanafy_memory(&(nana->data_memory));
		case NANAFY_TEXT_SECTION: 
			return tell_nanafy_memory(&(nana->text_memory));
		default:
			return 0;
	}
}
