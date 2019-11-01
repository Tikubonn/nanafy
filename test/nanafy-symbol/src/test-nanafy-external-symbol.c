#include <test.h>
#include <nanafy.h>
#include <windows.h>

void test_nanafy_external_symbol (){
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
	test(allocate_nanafy_manually(32, NANAFY_TEXT_SECTION, &nana) == 0);
	test(allocate_nanafy_manually(32, NANAFY_DATA_SECTION, &nana) == 0);
	test(allocate_nanafy_manually(32, NANAFY_RODATA_SECTION, &nana) == 0);
	test(allocate_nanafy_manually(32, NANAFY_BSS_SECTION, &nana) == 0);
	// *init 
	nanafy_symbol externalsym;
	init_nanafy_external_symbol(128, &externalsym);
	// *sizeof
	test(sizeof_nanafy_symbol_product(&externalsym) == sizeof(IMAGE_SYMBOL));
	// *read twice
	{
		IMAGE_SYMBOL isymbol;
		size_t readsize;
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), 0, &externalsym, &nana, &readsize) == 0);
		test(readsize == sizeof(isymbol));
		// *check
		test(isymbol.N.Name.Short == 0);
		test(isymbol.N.Name.Long == 128 +4);
		test(isymbol.Value == 0);
		test(isymbol.SectionNumber == 0); // none=0
		test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
		test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
		test(isymbol.NumberOfAuxSymbols == 0);
		// *read eof
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), sizeof(isymbol), &externalsym, &nana, &readsize) == 0);
		test(readsize == 0);
	}
}
