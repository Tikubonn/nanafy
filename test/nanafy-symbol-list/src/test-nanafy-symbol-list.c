#include <test.h>
#include <nanafy.h>
#include <windows.h>

#define LIST_LENGTH 128

void test_nanafy_symbol_list (){
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
	nanafy_symbol listseq[LIST_LENGTH];
	nanafy_symbol_list list;
	init_nanafy_symbol_list(listseq, LIST_LENGTH, &list);
	nanafy_symbol textsym;
	nanafy_symbol datasym;
	nanafy_symbol rodatasym;
	nanafy_symbol bsssym;
	nanafy_symbol externalsym;
	init_nanafy_symbol(NANAFY_TEXT_SECTION, 32, 128, &textsym);
	init_nanafy_symbol(NANAFY_DATA_SECTION, 32, 128, &datasym);
	init_nanafy_symbol(NANAFY_RODATA_SECTION, 32, 128, &rodatasym);
	init_nanafy_symbol(NANAFY_BSS_SECTION, 32, 128, &bsssym);
	init_nanafy_external_symbol(128, &externalsym);
	// *add
	{
		size_t index;
		test(add_nanafy_symbol_list(textsym, &list, &index) == 0);
	}
	// *add
	{
		size_t index;
		test(add_nanafy_symbol_list(datasym, &list, &index) == 0);
	}
	// *add
	{
		size_t index;
		test(add_nanafy_symbol_list(rodatasym, &list, &index) == 0);
	}
	// *add
	{
		size_t index;
		test(add_nanafy_symbol_list(bsssym, &list, &index) == 0);
	}
	// *add
	{
		size_t index;
		test(add_nanafy_symbol_list(externalsym, &list, &index) == 0);
	}
	// *read
	{
		size_t offset = 0;
		// *read
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_symbol_list_product(&isymbol, sizeof(isymbol), offset, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			// *check
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == 128 + 4);
			test(isymbol.Value == 32);
			test(isymbol.SectionNumber == 1); // .text=1
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_symbol_list_product(&isymbol, sizeof(isymbol), offset, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			// *check
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == 128 + 4);
			test(isymbol.Value == 32);
			test(isymbol.SectionNumber == 2); // .data=2
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_symbol_list_product(&isymbol, sizeof(isymbol), offset, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			// *check
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == 128 + 4);
			test(isymbol.Value == 32);
			test(isymbol.SectionNumber == 3); // .rodata=3
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_symbol_list_product(&isymbol, sizeof(isymbol), offset, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			// *check
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == 128 + 4);
			test(isymbol.Value == 32);
			test(isymbol.SectionNumber == 4); // .bss=4
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_symbol_list_product(&isymbol, sizeof(isymbol), offset, &list, &nana, &readsize) == 0);
			test(readsize == sizeof(isymbol));
			// *check
			test(isymbol.N.Name.Short == 0);
			test(isymbol.N.Name.Long == 128 + 4);
			test(isymbol.Value == 0);
			test(isymbol.SectionNumber == 0);
			test(isymbol.Type == IMAGE_SYM_TYPE_NULL);
			test(isymbol.StorageClass == IMAGE_SYM_CLASS_EXTERNAL);
			test(isymbol.NumberOfAuxSymbols == 0);
			offset += readsize;
		}
		// *read eof
		{
			IMAGE_SYMBOL isymbol;
			size_t readsize;
			test(read_nanafy_symbol_list_product(&isymbol, sizeof(isymbol), offset, &list, &nana, &readsize) == 0);
			test(readsize == 0);
		}
	}
}
