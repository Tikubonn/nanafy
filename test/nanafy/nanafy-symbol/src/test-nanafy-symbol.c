#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

#define SYMTEXT "text"
#define SYMDATA "data"
#define SYMRODATA "rodata"
#define SYMBSS "bss"
#define SYMEXTERNAL "external"

void test_nanafy_symbol (){
	nanafy_info nanainfo;
	setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
	nanafy *nana = make_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
	test(nana != NULL);
	// *allocate
	test(allocate_nanafy(8, NANAFY_TEXT_SECTION, nana) == 0);
	test(allocate_nanafy(8, NANAFY_DATA_SECTION, nana) == 0);
	test(allocate_nanafy(8, NANAFY_RODATA_SECTION, nana) == 0);
	test(allocate_nanafy(8, NANAFY_BSS_SECTION, nana) == 0);
	// *register
	size_t textsymid;
	test(register_nanafy_symbol(SYMTEXT, sizeof(SYMTEXT) -1, NANAFY_TEXT_SECTION, nana, &textsymid) == 0);
	// *register
	size_t datasymid;
	test(register_nanafy_symbol(SYMDATA, sizeof(SYMDATA) -1, NANAFY_DATA_SECTION, nana, &datasymid) == 0);
	// *register
	size_t rodatasymid;
	test(register_nanafy_symbol(SYMRODATA, sizeof(SYMRODATA) -1, NANAFY_RODATA_SECTION, nana, &rodatasymid) == 0);
	// *register
	size_t bsssymid;
	test(register_nanafy_symbol(SYMBSS, sizeof(SYMBSS) -1, NANAFY_BSS_SECTION, nana, &bsssymid) == 0);
	// *register
	size_t externalsymid;
	test(register_nanafy_external_symbol(SYMEXTERNAL, sizeof(SYMEXTERNAL) -1, nana, &externalsymid) == 0);
	// *read
	{
		size_t offset = 0;
		// *read file header
		{
			IMAGE_FILE_HEADER ifheader;
			size_t readsize;
			test(read_nanafy_product(&ifheader, sizeof(ifheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(ifheader));
			offset += readsize;
		}
		// *read text section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			test(isheader.Name[0] == '.');
			test(isheader.Name[1] == 't');
			test(isheader.Name[2] == 'e');
			test(isheader.Name[3] == 'x');
			test(isheader.Name[4] == 't');
			test(isheader.Name[5] == '\0');
			test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
			test(isheader.Characteristics & IMAGE_SCN_MEM_EXECUTE);
			//test(isheader.Misc.VirtualSize == 0);
			test(isheader.VirtualAddress == 0);
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4);
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += readsize;
		}
		// *read data section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			test(isheader.Name[0] == '.');
			test(isheader.Name[1] == 'd');
			test(isheader.Name[2] == 'a');
			test(isheader.Name[3] == 't');
			test(isheader.Name[4] == 'a');
			test(isheader.Name[5] == '\0');
			test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
			test(isheader.Characteristics & IMAGE_SCN_MEM_WRITE);
			//test(isheader.Misc.VirtualSize == 0);
			test(isheader.VirtualAddress == 8); // after .text
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4 + 8); // after .text
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += readsize;
		}
		// *read rodata section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			test(isheader.Name[0] == '.');
			test(isheader.Name[1] == 'r');
			test(isheader.Name[2] == 'o');
			test(isheader.Name[3] == 'd');
			test(isheader.Name[4] == 'a');
			test(isheader.Name[5] == 't');
			test(isheader.Name[6] == 'a');
			test(isheader.Name[7] == '\0');
			test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
			//test(isheader.Misc.VirtualSize == 0);
			test(isheader.VirtualAddress == 16); // after .data
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4 + 16); // after .data
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += readsize;
		}
		// *read bss section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			test(isheader.Name[0] == '.');
			test(isheader.Name[1] == 'b');
			test(isheader.Name[2] == 's');
			test(isheader.Name[3] == 's');
			test(isheader.Name[4] == '\0');
			test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
			test(isheader.Characteristics & IMAGE_SCN_MEM_WRITE);
			//test(isheader.Misc.VirtualSize == 0);
			test(isheader.VirtualAddress == 24); // after .rodata
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == 0); // .bss has no pointer!
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += readsize;
		}
		// *read text binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			offset += readsize;
		}
		// *read data binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			offset += readsize;
		}
		// *read rodata binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			offset += readsize;
		}
		// *read text symbol
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_product(&isymbol, sizeof(isymbol), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == 4); 
			test(isymbol.Value == 8);
			test(isymbol.SectionNumber == 1); // .text=1
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read data symbol
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_product(&isymbol, sizeof(isymbol), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == sizeof(SYMTEXT) +4);
			test(isymbol.Value == 8);
			test(isymbol.SectionNumber == 2); // .data=1
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read rodata symbol
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_product(&isymbol, sizeof(isymbol), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == sizeof(SYMTEXT) + sizeof(SYMDATA) +4);
			test(isymbol.Value == 8);
			test(isymbol.SectionNumber == 3); // .rodata=3
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read bss symbol
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_product(&isymbol, sizeof(isymbol), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == sizeof(SYMTEXT) + sizeof(SYMDATA) + sizeof(SYMRODATA) +4);
			test(isymbol.Value == 8);
			test(isymbol.SectionNumber == 4); // .bss=4
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read external symbol
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_product(&isymbol, sizeof(isymbol), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == sizeof(SYMTEXT) + sizeof(SYMDATA) + sizeof(SYMRODATA) + sizeof(SYMBSS) +4);
			test(isymbol.Value == 0);
			test(isymbol.SectionNumber == 0); // external=0
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read table size
		{
			DWORD tablesize;
			size_t readsize;
			test(read_nanafy_product(&tablesize, sizeof(tablesize), offset, nana, &readsize) == 0);
			test(readsize == 4);
			test(tablesize == sizeof(SYMTEXT) + sizeof(SYMDATA) + sizeof(SYMRODATA) + sizeof(SYMBSS) + sizeof(SYMEXTERNAL) +4);
			offset += readsize;
		}
		// *read symname table 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, sizeof(buffer), offset,  nana, &readsize) == 0);
			test(readsize == sizeof(SYMTEXT) + sizeof(SYMDATA) + sizeof(SYMRODATA) + sizeof(SYMBSS) + sizeof(SYMEXTERNAL));
			test(buffer[0] == 't');
			test(buffer[1] == 'e');
			test(buffer[2] == 'x');
			test(buffer[3] == 't');
			test(buffer[4] == '\0');
			test(buffer[5] == 'd');
			test(buffer[6] == 'a');
			test(buffer[7] == 't');
			test(buffer[8] == 'a');
			test(buffer[9] == '\0');
			test(buffer[10] == 'r');
			test(buffer[11] == 'o');
			test(buffer[12] == 'd');
			test(buffer[13] == 'a');
			test(buffer[14] == 't');
			test(buffer[15] == 'a');
			test(buffer[16] == '\0');
			test(buffer[17] == 'b');
			test(buffer[18] == 's');
			test(buffer[19] == 's');
			test(buffer[20] == '\0');
			test(buffer[21] == 'e');
			test(buffer[22] == 'x');
			test(buffer[23] == 't');
			test(buffer[24] == 'e');
			test(buffer[25] == 'r');
			test(buffer[26] == 'n');
			test(buffer[27] == 'a');
			test(buffer[28] == 'l');
			test(buffer[29] == '\0');
			offset += readsize;
		}
	}
	free_nanafy(nana);
}
