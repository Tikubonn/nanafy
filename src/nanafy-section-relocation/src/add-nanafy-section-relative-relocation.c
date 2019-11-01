#include <nanafy.h>
#include <stddef.h>

nanafy_status add_nanafy_section_relative_relocation (size_t symid, nanafy_section section, size_t offset, size_t size, nanafy *nana){
	switch (section){
		case NANAFY_TEXT_SECTION: {
			nanafy_relocation relocation;
			init_nanafy_relative_relocation(symid, offset, size, &relocation);
			size_t index;
			if (add_nanafy_relocation_list(relocation, &(nana->text_relocation_list), &index) != 0){
				return NANAFY_TEXT_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		}
		case NANAFY_DATA_SECTION: {
			nanafy_relocation relocation;
			init_nanafy_relative_relocation(symid, offset, size, &relocation);
			size_t index;
			if (add_nanafy_relocation_list(relocation, &(nana->data_relocation_list), &index) != 0){
				return NANAFY_DATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		}
		case NANAFY_RODATA_SECTION: {
			nanafy_relocation relocation;
			init_nanafy_relative_relocation(symid, offset, size, &relocation);
			size_t index;
			if (add_nanafy_relocation_list(relocation, &(nana->rodata_relocation_list), &index) != 0){
				return NANAFY_RODATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY;
			}
			return NANAFY_SUCCESS;
		}
		default:
			return NANAFY_ERROR;
	}
}
