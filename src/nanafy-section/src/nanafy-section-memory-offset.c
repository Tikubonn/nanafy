#include <nanafy.h>
#include <stddef.h>

/*
	text => data => rodata => bss 
	プロセス内のメモリに展開された際の位置を返します。
*/

size_t nanafy_section_memory_offset (nanafy_section section, nanafy *nana){
	size_t offset = 0;
	switch (section){
		case NANAFY_BSS_SECTION: 
			offset += tell_nanafy_memory(&(nana->rodata_memory));
		case NANAFY_RODATA_SECTION: 
			offset += tell_nanafy_memory(&(nana->data_memory));
		case NANAFY_DATA_SECTION: 
			offset += tell_nanafy_memory(&(nana->text_memory));
		default:
			break;
	}
	return offset;
}
