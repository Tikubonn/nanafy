#include <nanafy.h>
#include <stddef.h>

int read_nanafy_section_product (void *sequence, size_t size, size_t offset, nanafy_section section, nanafy *nana, size_t *readsizep){
	switch (section){
		case NANAFY_TEXT_SECTION:
			return read_nanafy_memory_product(sequence, size, offset, &(nana->text_memory), readsizep);
		case NANAFY_DATA_SECTION:
			return read_nanafy_memory_product(sequence, size, offset, &(nana->data_memory), readsizep);
		case NANAFY_RODATA_SECTION:
			return read_nanafy_memory_product(sequence, size, offset, &(nana->rodata_memory), readsizep);
		case NANAFY_BSS_SECTION:
			return read_nanafy_uninited_memory_product(sequence, size, offset, &(nana->bss_memory), readsizep);
		default:
			return 1;
	}
}
