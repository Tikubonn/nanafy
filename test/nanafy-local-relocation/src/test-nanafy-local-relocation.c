#include <test.h>
#include <nanafy.h>
#include <stddef.h>

void test_nanafy_local_relocation (){
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
	nanafy_local_relocation textrelocation1;
	nanafy_local_relocation textrelocation2;
	nanafy_local_relocation textrelocation3;
	init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 4, 0, 4, &textrelocation1); // 4-(0+4)=0
	init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 4, 4, 4, &textrelocation2); // 0-(0+4)=-4
	init_nanafy_local_relocation(NANAFY_TEXT_SECTION, 0, 4, 4, &textrelocation3); // 0-(4+4)=-8
	// *init data
	nanafy_local_relocation datarelocation1;
	nanafy_local_relocation datarelocation2;
	nanafy_local_relocation datarelocation3;
	init_nanafy_local_relocation(NANAFY_DATA_SECTION, 4, 0, 4, &datarelocation1); // 4-(0+4)=0
	init_nanafy_local_relocation(NANAFY_DATA_SECTION, 4, 4, 4, &datarelocation2); // 0-(0+4)=-4
	init_nanafy_local_relocation(NANAFY_DATA_SECTION, 0, 4, 4, &datarelocation3); // 0-(4+4)=-8
	// *init rodata
	nanafy_local_relocation rodatarelocation1;
	nanafy_local_relocation rodatarelocation2;
	nanafy_local_relocation rodatarelocation3;
	init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 4, 0, 4, &rodatarelocation1); // 4-(0+4)=0
	init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 4, 4, 4, &rodatarelocation2); // 0-(0+4)=-4
	init_nanafy_local_relocation(NANAFY_RODATA_SECTION, 0, 4, 4, &rodatarelocation3); // 0-(4+4)=-8
	// *samep text
	test(same_nanafy_local_relocation_placep(&textrelocation1, &textrelocation3) == false);
	test(same_nanafy_local_relocation_placep(&textrelocation2, &textrelocation3) == true);
	test(same_nanafy_local_relocation_placep(&textrelocation3, &textrelocation3) == true);
	// *samep data
	test(same_nanafy_local_relocation_placep(&datarelocation1, &datarelocation3) == false);
	test(same_nanafy_local_relocation_placep(&datarelocation2, &datarelocation3) == true);
	test(same_nanafy_local_relocation_placep(&datarelocation3, &datarelocation3) == true);
	// *samep rodata
	test(same_nanafy_local_relocation_placep(&rodatarelocation1, &rodatarelocation3) == false);
	test(same_nanafy_local_relocation_placep(&rodatarelocation2, &rodatarelocation3) == true);
	test(same_nanafy_local_relocation_placep(&rodatarelocation3, &rodatarelocation3) == true);
	// *fix 
	test(fix_nanafy_memory_with_local_relocation(&textrelocation1, &nana) == 0);
	test(fix_nanafy_memory_with_local_relocation(&textrelocation2, &nana) == 0);
	test(fix_nanafy_memory_with_local_relocation(&datarelocation1, &nana) == 0);
	test(fix_nanafy_memory_with_local_relocation(&datarelocation2, &nana) == 0);
	test(fix_nanafy_memory_with_local_relocation(&rodatarelocation1, &nana) == 0);
	test(fix_nanafy_memory_with_local_relocation(&rodatarelocation2, &nana) == 0);
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_TEXT_SECTION, &nana, &readsize) == 0);
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
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_DATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		// +0
		test(buffer[0] == 0);
		test(buffer[1] == 0);
		test(buffer[2] == 0);
		test(buffer[3] == 0);
		// -4
		test(buffer[4] == -4);
		test(buffer[5] == -1);
		test(buffer[5] == -1);
		test(buffer[6] == -1);
	}
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_RODATA_SECTION, &nana, &readsize) == 0);
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
