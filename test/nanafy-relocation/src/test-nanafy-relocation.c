#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

void test_nanafy_relocation (){
	nanafy_info nanainfo;
	setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
	nanafy nana;
	init_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo, &nana);
	// *remap 
	char textseq[128];
	char dataseq[128];
	char rodataseq[128];
	test(remap_nanafy_text_memory(textseq, sizeof(textseq), &nana) == 0);
	test(remap_nanafy_data_memory(dataseq, sizeof(dataseq), &nana) == 0);
	test(remap_nanafy_rodata_memory(rodataseq, sizeof(rodataseq), &nana) == 0);
	// *allocate
	test(allocate_nanafy_section(8, NANAFY_TEXT_SECTION, &nana) == 0);
	test(allocate_nanafy_section(8, NANAFY_DATA_SECTION, &nana) == 0);
	test(allocate_nanafy_section(8, NANAFY_RODATA_SECTION, &nana) == 0);
	// *init text
	nanafy_relocation textrelocation;
	nanafy_relocation textrelrelocation;
	init_nanafy_relocation(128, 0, 4, &textrelocation);
	init_nanafy_relative_relocation(128, 0, 4, &textrelrelocation);
	// *init data
	nanafy_relocation datarelocation;
	nanafy_relocation datarelrelocation;
	init_nanafy_relocation(128, 0, 4, &datarelocation);
	init_nanafy_relative_relocation(128, 0, 4, &datarelrelocation);
	// *init rodata
	nanafy_relocation rodatarelocation;
	nanafy_relocation rodatarelrelocation;
	init_nanafy_relocation(128, 0, 4, &rodatarelocation);
	init_nanafy_relative_relocation(128, 0, 4, &rodatarelrelocation);
	// *read
	{
		IMAGE_RELOCATION irelocation;
		size_t readsize;
		test(read_nanafy_relocation_product(&irelocation, sizeof(irelocation), 0, NANAFY_TEXT_SECTION, &textrelocation, &nana, &readsize) == 0);
		test(readsize == sizeof(irelocation));
		test(irelocation.VirtualAddress == 0);
		test(irelocation.SymbolTableIndex == 128);
		test(irelocation.Type == IMAGE_REL_I386_DIR32);
	}
	// *read
	{
		IMAGE_RELOCATION irelocation;
		size_t readsize;
		test(read_nanafy_relocation_product(&irelocation, sizeof(irelocation), 0, NANAFY_TEXT_SECTION, &textrelrelocation, &nana, &readsize) == 0);
		test(readsize == sizeof(irelocation));
		test(irelocation.VirtualAddress == 0);
		test(irelocation.SymbolTableIndex == 128);
		test(irelocation.Type == IMAGE_REL_I386_REL32);
	}
	// *read
	{
		IMAGE_RELOCATION irelocation;
		size_t readsize;
		test(read_nanafy_relocation_product(&irelocation, sizeof(irelocation), 0, NANAFY_DATA_SECTION, &datarelocation, &nana, &readsize) == 0);
		test(readsize == sizeof(irelocation));
		test(irelocation.VirtualAddress == 8);
		test(irelocation.SymbolTableIndex == 128);
		test(irelocation.Type == IMAGE_REL_I386_DIR32);
	}
	// *read
	{
		IMAGE_RELOCATION irelocation;
		size_t readsize;
		test(read_nanafy_relocation_product(&irelocation, sizeof(irelocation), 0, NANAFY_DATA_SECTION, &datarelrelocation, &nana, &readsize) == 0);
		test(readsize == sizeof(irelocation));
		test(irelocation.VirtualAddress == 8);
		test(irelocation.SymbolTableIndex == 128);
		test(irelocation.Type == IMAGE_REL_I386_REL32);
	}
	// *read
	{
		IMAGE_RELOCATION irelocation;
		size_t readsize;
		test(read_nanafy_relocation_product(&irelocation, sizeof(irelocation), 0, NANAFY_RODATA_SECTION, &rodatarelocation, &nana, &readsize) == 0);
		test(readsize == sizeof(irelocation));
		test(irelocation.VirtualAddress == 16);
		test(irelocation.SymbolTableIndex == 128);
		test(irelocation.Type == IMAGE_REL_I386_DIR32);
	}
	// *read
	{
		IMAGE_RELOCATION irelocation;
		size_t readsize;
		test(read_nanafy_relocation_product(&irelocation, sizeof(irelocation), 0, NANAFY_RODATA_SECTION, &rodatarelrelocation, &nana, &readsize) == 0);
		test(readsize == sizeof(irelocation));
		test(irelocation.VirtualAddress == 16);
		test(irelocation.SymbolTableIndex == 128);
		test(irelocation.Type == IMAGE_REL_I386_REL32);
	}
}
