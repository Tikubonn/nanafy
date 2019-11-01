#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

#define LIST_LENGTH 128

void test_nanafy_relocation_list (){
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
	// *init 
	nanafy_relocation listseq[LIST_LENGTH];
	nanafy_relocation_list list;
	init_nanafy_relocation_list(listseq, LIST_LENGTH, &list);
	// *allocate
	test(allocate_nanafy_section(8, NANAFY_TEXT_SECTION, &nana) == 0);
	test(allocate_nanafy_section(8, NANAFY_DATA_SECTION, &nana) == 0);
	test(allocate_nanafy_section(8, NANAFY_RODATA_SECTION, &nana) == 0);
	// *add text
	{
		nanafy_relocation relocation;
		init_nanafy_relocation(128, 0, 4, &relocation);
		size_t index;
		test(add_nanafy_relocation_list(relocation, &list, &index) == 0);
	}
	// *add text
	{
		nanafy_relocation relocation;
		init_nanafy_relative_relocation(128, 0, 4, &relocation);
		size_t index;
		test(add_nanafy_relocation_list(relocation, &list, &index) == 0);
	}
	// *add data
	{
		nanafy_relocation relocation;
		init_nanafy_relocation(128, 0, 4, &relocation);
		size_t index;
		test(add_nanafy_relocation_list(relocation, &list, &index) == 0);
	}
	// *add data
	{
		nanafy_relocation relocation;
		init_nanafy_relative_relocation(128, 0, 4, &relocation);
		size_t index;
		test(add_nanafy_relocation_list(relocation, &list, &index) == 0);
	}
	// *add rodata
	{
		nanafy_relocation relocation;
		init_nanafy_relocation(128, 0, 4, &relocation);
		size_t index;
		test(add_nanafy_relocation_list(relocation, &list, &index) == 0);
	}
	// *add rodata
	{
		nanafy_relocation relocation;
		init_nanafy_relative_relocation(128, 0, 4, &relocation);
		size_t index;
		test(add_nanafy_relocation_list(relocation, &list, &index) == 0);
	}
	// *read
	{
		size_t offset = 0;
		// *read text
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_relocation_list_product(&irelocation, sizeof(irelocation), offset, NANAFY_TEXT_SECTION, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 0);
			test(irelocation.SymbolTableIndex == 128);
			test(irelocation.Type == IMAGE_REL_I386_DIR32);
			offset += readsize;
			
		}
		// *read text
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_relocation_list_product(&irelocation, sizeof(irelocation), offset, NANAFY_TEXT_SECTION, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 0);
			test(irelocation.SymbolTableIndex == 128);
			test(irelocation.Type == IMAGE_REL_I386_REL32);
			offset += readsize;
		}
		// *read data
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_relocation_list_product(&irelocation, sizeof(irelocation), offset, NANAFY_DATA_SECTION, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 8);
			test(irelocation.SymbolTableIndex == 128);
			test(irelocation.Type == IMAGE_REL_I386_DIR32);
			offset += readsize;
			
		}
		// *read data
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_relocation_list_product(&irelocation, sizeof(irelocation), offset, NANAFY_DATA_SECTION, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 8);
			test(irelocation.SymbolTableIndex == 128);
			test(irelocation.Type == IMAGE_REL_I386_REL32);
			offset += readsize;
		}
		// *read rodata
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_relocation_list_product(&irelocation, sizeof(irelocation), offset, NANAFY_RODATA_SECTION, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 16);
			test(irelocation.SymbolTableIndex == 128);
			test(irelocation.Type == IMAGE_REL_I386_DIR32);
			offset += readsize;
			
		}
		// *read rodata
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_relocation_list_product(&irelocation, sizeof(irelocation), offset, NANAFY_RODATA_SECTION, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 16);
			test(irelocation.SymbolTableIndex == 128);
			test(irelocation.Type == IMAGE_REL_I386_REL32);
			offset += readsize;
		}
	}
}
