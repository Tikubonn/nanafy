#include <nanafy.h>
#include <stddef.h>

int read_nanafy_relocation_list_product (void *sequence, size_t size, size_t offset, nanafy_section section, nanafy_relocation_list *list, nanafy *nana, size_t *readsizep){
	size_t off = 0;
	size_t length = nanafy_relocation_list_length(list);
	for (size_t index = 0; index < length; index++){
		nanafy_relocation relocation;
		if (get_nanafy_relocation_list(index, list, &relocation) != 0){
			return 1;
		}
		size_t symsize = sizeof_nanafy_relocation_product(section, &relocation);
		if (0 < symsize){
			if (offset < off + symsize){
				size_t of = offset - off;
				return read_nanafy_relocation_product(sequence, size, of, section, &relocation, nana, readsizep);
			}
		}
		off += symsize;
	}
	*readsizep = 0;
	return 0;
}
