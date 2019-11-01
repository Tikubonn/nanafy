#include <nanafy.h>
#include <stddef.h>

int fix_nanafy_memory_with_local_relocation (nanafy_local_relocation *relocation, nanafy *nana){
	size_t newoffset = relocation->offsetfrom - (relocation->offsetto + relocation->size);
	char buffer[32]; // temporary buffer!
	if (sizeof(buffer) < relocation->size){
		return 1;
	}
	endian_nanafy(newoffset, nana->info.endian, buffer, relocation->size);
	for (size_t index = 0; index < relocation->size; index++){
		if (set_nanafy_section(buffer[index], relocation->section, relocation->offsetto + index, nana) != 0){
			return 1;
		}
	}
	return 0;
}
