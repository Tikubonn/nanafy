#include <nanafy.h>
#include <stddef.h>

void init_nanafy_local_relocation (nanafy_section section, size_t offsetfrom, size_t offsetto, size_t size, nanafy_local_relocation *relocation){
	relocation->section = section;
	relocation->offsetfrom = offsetfrom;
	relocation->offsetto = offsetto;
	relocation->size = size;
}
