#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

int setup_image_relocation_with_nanafy_relocation (nanafy_section section, nanafy_relocation *relocation, nanafy *nana, IMAGE_RELOCATION *irelocation){
	bool found;
	nanafy_relocation_info reinfo;
	find_nanafy_relocation_info(relocation->type, relocation->size, &(nana->info), &found, &reinfo);
	if (found == true){
		size_t offset = nanafy_section_memory_offset(section, nana);
		irelocation->VirtualAddress = offset + relocation->offset;
		irelocation->SymbolTableIndex = relocation->symbolid;
		irelocation->Type = reinfo.relocation_type;
		return 0; // ok!
	}
	return 1; // your relocation request is unsupported!
}
