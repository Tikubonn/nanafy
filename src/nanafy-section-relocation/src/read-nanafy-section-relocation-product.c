#include <nanafy.h>
#include <stddef.h>

int read_nanafy_section_relocation_product (void *sequence, size_t size, size_t offset, nanafy_section section, nanafy *nana, size_t *readsizep){
	switch (section){
		case NANAFY_TEXT_SECTION:
			return read_nanafy_relocation_list_product(sequence, size, offset, section, &(nana->text_relocation_list), nana, readsizep);
		case NANAFY_DATA_SECTION:
			return read_nanafy_relocation_list_product(sequence, size, offset, section, &(nana->data_relocation_list), nana, readsizep);
		case NANAFY_RODATA_SECTION:
			return read_nanafy_relocation_list_product(sequence, size, offset, section, &(nana->rodata_relocation_list), nana, readsizep);
		default:
			return 1;
	}
}
