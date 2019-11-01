#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

void test_nanafy_memory (){
	nanafy_info nanainfo;
	setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
	nanafy *nana = make_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
	test(nana != NULL);
	// *put
	test(put_nanafy('a', NANAFY_TEXT_SECTION, nana) == 0);
	test(tell_nanafy(NANAFY_TEXT_SECTION, nana) == 1);
	// *put
	test(put_nanafy('a', NANAFY_DATA_SECTION, nana) == 0);
	test(tell_nanafy(NANAFY_DATA_SECTION, nana) == 1);
	// *put
	test(put_nanafy('a', NANAFY_RODATA_SECTION, nana) == 0);
	test(tell_nanafy(NANAFY_RODATA_SECTION, nana) == 1);
	// *write
	{
		char example[] = { 'b', 'c' };
		test(write_nanafy(example, sizeof(example), NANAFY_TEXT_SECTION, nana) == 0);
		test(tell_nanafy(NANAFY_TEXT_SECTION, nana) == 3);
	}
	// *write
	{
		char example[] = { 'b', 'c' };
		test(write_nanafy(example, sizeof(example), NANAFY_DATA_SECTION, nana) == 0);
		test(tell_nanafy(NANAFY_DATA_SECTION, nana) == 3);
	}
	// *write
	{
		char example[] = { 'b', 'c' };
		test(write_nanafy(example, sizeof(example), NANAFY_RODATA_SECTION, nana) == 0);
		test(tell_nanafy(NANAFY_RODATA_SECTION, nana) == 3);
	}
	// *allocate
	test(allocate_nanafy(3, NANAFY_TEXT_SECTION, nana) == 0);
	test(allocate_nanafy(3, NANAFY_DATA_SECTION, nana) == 0);
	test(allocate_nanafy(3, NANAFY_RODATA_SECTION, nana) == 0);
	test(allocate_nanafy(6, NANAFY_BSS_SECTION, nana) == 0);
	// *align 
	test(align_nanafy(0, 8, NANAFY_TEXT_SECTION, nana) == 0);
	test(align_nanafy(0, 8, NANAFY_DATA_SECTION, nana) == 0);
	test(align_nanafy(0, 8, NANAFY_RODATA_SECTION, nana) == 0);
	test(align_nanafy(0, 8, NANAFY_BSS_SECTION, nana) == 0);
	// *read
	{
		size_t offset = 0;
		// *read
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
			test(buffer[0] == 'a');
			test(buffer[1] == 'b');
			test(buffer[2] == 'c');
			test(buffer[3] == 0);
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
			offset += readsize;
		}
		// *read data binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			test(buffer[0] == 'a');
			test(buffer[1] == 'b');
			test(buffer[2] == 'c');
			test(buffer[3] == 0);
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
			offset += readsize;
		}
		// *read rodata binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			test(buffer[0] == 'a');
			test(buffer[1] == 'b');
			test(buffer[2] == 'c');
			test(buffer[3] == 0);
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
			offset += readsize;
		}
	}
	// *free
	free_nanafy(nana);
}
