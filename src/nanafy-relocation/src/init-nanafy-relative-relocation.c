#include <nanafy.h>
#include <stddef.h>

void init_nanafy_relative_relocation (size_t symid, size_t offset, size_t size, nanafy_relocation *relocation){
	relocation->type = NANAFY_RELATIVE_RELOCATION;
	relocation->offset = offset;
	relocation->size = size;
	relocation->symbolid = symid;
}
