#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

int setup_image_file_header_with_nanafy (nanafy *nana, IMAGE_FILE_HEADER *ifheader){
	ifheader->Machine = nana->info.machine;
	ifheader->NumberOfSections = 
		countof_nanafy_image_section_header_product(nana);
	ifheader->TimeDateStamp = 0; // define later!
	ifheader->PointerToSymbolTable = 
		sizeof_nanafy_image_file_header_product(nana) + 
		sizeof_nanafy_all_image_section_header_product(nana) + 
		sizeof_nanafy_all_section_product(nana) + 
		sizeof_nanafy_all_section_relocation_product(nana);
	ifheader->NumberOfSymbols = 
		nanafy_symbol_list_length(&(nana->symbol_list));
	ifheader->SizeOfOptionalHeader = 0;
	ifheader->Characteristics = 0;
	return 0;
}
