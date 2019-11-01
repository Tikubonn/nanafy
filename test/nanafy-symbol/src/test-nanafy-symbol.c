#include <test.h>
#include <nanafy.h>
#include <windows.h>

void test_nanafy_symbol (){
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
	nanafy_symbol textsym;
	nanafy_symbol datasym;
	nanafy_symbol rodatasym;
	nanafy_symbol bsssym;
	init_nanafy_symbol(NANAFY_TEXT_SECTION, 32, 128, &textsym);
	init_nanafy_symbol(NANAFY_DATA_SECTION, 32, 128, &datasym);
	init_nanafy_symbol(NANAFY_RODATA_SECTION, 32, 128, &rodatasym);
	init_nanafy_symbol(NANAFY_BSS_SECTION, 32, 128, &bsssym);
	// *sizeof
	test(sizeof_nanafy_symbol_product(&textsym) == sizeof(IMAGE_SYMBOL));
	test(sizeof_nanafy_symbol_product(&datasym) == sizeof(IMAGE_SYMBOL));
	test(sizeof_nanafy_symbol_product(&rodatasym) == sizeof(IMAGE_SYMBOL));
	test(sizeof_nanafy_symbol_product(&bsssym) == sizeof(IMAGE_SYMBOL));
	// *read twice
	{
		IMAGE_SYMBOL isymbol;
		size_t readsize;
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), 0, &textsym, &nana, &readsize) == 0);
		test(readsize == sizeof(isymbol));
		// *check
		test(isymbol.N.Name.Short == 0);
		test(isymbol.N.Name.Long == 128 +4);
		test(isymbol.Value == 32);
		test(isymbol.SectionNumber == 1); // .text=1
		test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
		test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
		test(isymbol.NumberOfAuxSymbols == 0);
		// *read eof
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), sizeof(isymbol), &textsym, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read twice
	{
		IMAGE_SYMBOL isymbol;
		size_t readsize;
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), 0, &datasym, &nana, &readsize) == 0);
		test(readsize == sizeof(isymbol));
		// *check
		test(isymbol.N.Name.Short == 0);
		test(isymbol.N.Name.Long == 128 +4);
		test(isymbol.Value == 32);
		test(isymbol.SectionNumber == 2); // .data=2
		test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
		test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
		test(isymbol.NumberOfAuxSymbols == 0);
		// *read eof
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), sizeof(isymbol), &textsym, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read twice
	{
		IMAGE_SYMBOL isymbol;
		size_t readsize;
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), 0, &rodatasym, &nana, &readsize) == 0);
		test(readsize == sizeof(isymbol));
		// *check
		test(isymbol.N.Name.Short == 0);
		test(isymbol.N.Name.Long == 128 +4);
		test(isymbol.Value == 32);
		test(isymbol.SectionNumber == 3); // .rodata=3
		test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
		test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
		test(isymbol.NumberOfAuxSymbols == 0);
		// *read eof
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), sizeof(isymbol), &textsym, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read twice
	{
		IMAGE_SYMBOL isymbol;
		size_t readsize;
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), 0, &bsssym, &nana, &readsize) == 0);
		test(readsize == sizeof(isymbol));
		// *check
		test(isymbol.N.Name.Short == 0);
		test(isymbol.N.Name.Long == 128 +4);
		test(isymbol.Value == 32);
		test(isymbol.SectionNumber == 4); // .bss=4
		test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
		test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
		test(isymbol.NumberOfAuxSymbols == 0);
		// *read eof
		test(read_nanafy_symbol_product(&isymbol, sizeof(isymbol), sizeof(isymbol), &textsym, &nana, &readsize) == 0);
		test(readsize == 0);
	}
}
