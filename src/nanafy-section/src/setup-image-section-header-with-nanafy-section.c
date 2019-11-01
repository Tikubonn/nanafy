#include <nanafy.h>
#include <stddef.h>
#include <windows.h>
		
int setup_image_section_header_with_nanafy_section (nanafy_section section, nanafy *nana, IMAGE_SECTION_HEADER *isheader){
	switch (section){
		case NANAFY_TEXT_SECTION:
			isheader->Name[0] = '.';
			isheader->Name[1] = 't';
			isheader->Name[2] = 'e';
			isheader->Name[3] = 'x';
			isheader->Name[4] = 't';
			isheader->Name[5] = '\0';
			isheader->Name[6] = 0;
			isheader->Name[7] = 0;
			isheader->Characteristics = 
				IMAGE_SCN_MEM_EXECUTE |
				IMAGE_SCN_MEM_READ;
			break;
		case NANAFY_DATA_SECTION:
			isheader->Name[0] = '.';
			isheader->Name[1] = 'd';
			isheader->Name[2] = 'a';
			isheader->Name[3] = 't';
			isheader->Name[4] = 'a';
			isheader->Name[5] = '\0';
			isheader->Name[6] = 0;
			isheader->Name[7] = 0;
			isheader->Characteristics = 
				IMAGE_SCN_MEM_READ |
				IMAGE_SCN_MEM_WRITE;
			break;
		case NANAFY_RODATA_SECTION:
			isheader->Name[0] = '.';
			isheader->Name[1] = 'r';
			isheader->Name[2] = 'o';
			isheader->Name[3] = 'd';
			isheader->Name[4] = 'a';
			isheader->Name[5] = 't';
			isheader->Name[6] = 'a';
			isheader->Name[7] = '\0';
			isheader->Characteristics = 
				IMAGE_SCN_MEM_READ;
			break;
		case NANAFY_BSS_SECTION:
			isheader->Name[0] = '.';
			isheader->Name[1] = 'b';
			isheader->Name[2] = 's';
			isheader->Name[3] = 's';
			isheader->Name[4] = '\0';
			isheader->Name[5] = 0;
			isheader->Name[6] = 0;
			isheader->Name[7] = 0;
			isheader->Characteristics = 
				IMAGE_SCN_MEM_READ |
				IMAGE_SCN_MEM_WRITE;
			break;
		default:
			return 1;
	}
	isheader->Misc.VirtualSize = 0;
	isheader->VirtualAddress = nanafy_section_memory_offset(section, nana);
	/*
		.bss セクションの場合には PointerToRawData を 0 に設定し、
		SizeOfRawData に実際に要求されるメモリ量を与えます。
	*/
	if (section == NANAFY_BSS_SECTION){
		isheader->SizeOfRawData = nanafy_section_memory_size(section, nana);
		isheader->PointerToRawData = 0;
	}
	else {
		isheader->SizeOfRawData = nanafy_section_file_size(section, nana);
		isheader->PointerToRawData = 
			sizeof_nanafy_image_file_header_product(nana) + 
			sizeof_nanafy_all_image_section_header_product(nana) + 
			nanafy_section_file_offset(section, nana);
	}
	isheader->PointerToRelocations = 0;
	if (0 < countof_nanafy_section_relocation_product(section, nana)){
		isheader->PointerToRelocations = 
			sizeof_nanafy_image_file_header_product(nana) + 
			sizeof_nanafy_all_image_section_header_product(nana) + 
			sizeof_nanafy_all_section_product(nana) + 
			offsetof_nanafy_section_relocation_product(section, nana);
	}
	isheader->PointerToLinenumbers = 0;
	isheader->NumberOfRelocations = 
		countof_nanafy_section_relocation_product(section, nana);
	isheader->NumberOfLinenumbers = 0;
	return 0;
}
