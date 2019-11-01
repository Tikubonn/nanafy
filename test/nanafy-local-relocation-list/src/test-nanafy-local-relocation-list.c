#include <test.h>
#include <nanafy.h>
#include <stddef.h>

#define LIST_LENGTH 128

void test_nanafy_local_relocation_list (){
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
	nanafy_local_relocation reloclistseq[LIST_LENGTH];
	nanafy_local_relocation_list reloclist;
	init_nanafy_local_relocation_list(reloclistseq, LIST_LENGTH, &reloclist);
	// *allocate
	test(allocate_nanafy_section(8, NANAFY_TEXT_SECTION, &nana) == 0);
	test(allocate_nanafy_section(8, NANAFY_DATA_SECTION, &nana) == 0);
	test(allocate_nanafy_section(8, NANAFY_RODATA_SECTION, &nana) == 0);
	// *add
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 4, 0, 4, &relocation); // 4-(0+4)=0
		size_t index;
		test(add_nanafy_local_relocation_list(relocation, &reloclist, &index) == 0);
	}
	// *add
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 4, 4, 4, &relocation); // 0-(0+4)=-4
		size_t index;
		test(add_nanafy_local_relocation_list(relocation, &reloclist, &index) == 0);
	}
	// *add
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_DATA_SECTION, 4, 0, 4, &relocation); // 4-(0+4)=0
		size_t index;
		test(add_nanafy_local_relocation_list(relocation, &reloclist, &index) == 0);
	}
	// *add
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_DATA_SECTION, 4, 4, 4, &relocation); // 0-(0+4)=-4
		size_t index;
		test(add_nanafy_local_relocation_list(relocation, &reloclist, &index) == 0);
	}
	// *add
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 4, 0, 4, &relocation); // 4-(0+4)=0
		size_t index;
		test(add_nanafy_local_relocation_list(relocation, &reloclist, &index) == 0);
	}
	// *add
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 4, 4, 4, &relocation); // 0-(0+4)=-4
		size_t index;
		test(add_nanafy_local_relocation_list(relocation, &reloclist, &index) == 0);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 0, 0, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == true);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 0, 4, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == true);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 0, 8, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == false);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_DATA_SECTION, 0, 0, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == true);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_DATA_SECTION, 0, 4, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == true);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_DATA_SECTION, 0, 8, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == false);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 0, 0, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == true);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 0, 4, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == true);
	}
	// *find 
	{
		nanafy_local_relocation relocation;
		init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 0, 8, 4, &relocation);
		bool found;
		size_t foundindex;
		test(find_nanafy_local_relocation_list(&relocation, &reloclist, &found, &foundindex) == 0);
		test(found == false);
	}
	// *fix 
	test(fix_nanafy_memory_with_local_relocation_list(&reloclist, &nana) == 0);
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, 8, 0, NANAFY_TEXT_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		// +0
		test(buffer[0] == 0);
		test(buffer[1] == 0);
		test(buffer[2] == 0);
		test(buffer[3] == 0);
		// -4
		test(buffer[4] == -4);
		test(buffer[5] == -1);
		test(buffer[6] == -1);
		test(buffer[7] == -1);
	}
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, 8, 0, NANAFY_DATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		// +0
		test(buffer[0] == 0);
		test(buffer[1] == 0);
		test(buffer[2] == 0);
		test(buffer[3] == 0);
		// -4
		test(buffer[4] == -4);
		test(buffer[5] == -1);
		test(buffer[6] == -1);
		test(buffer[7] == -1);
	}
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, 8, 0, NANAFY_RODATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		// +0
		test(buffer[0] == 0);
		test(buffer[1] == 0);
		test(buffer[2] == 0);
		test(buffer[3] == 0);
		// -4
		test(buffer[4] == -4);
		test(buffer[5] == -1);
		test(buffer[6] == -1);
		test(buffer[7] == -1);
	}
}
