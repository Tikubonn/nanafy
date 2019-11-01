#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

void test_nanafy_section (){
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
	// *put
	test(put_nanafy_section(1, NANAFY_TEXT_SECTION, &nana) == NANAFY_SUCCESS);
	test(tell_nanafy_section(NANAFY_TEXT_SECTION, &nana) == 1);
	test(nanafy_section_memory_size(NANAFY_TEXT_SECTION, &nana) == 1);
	test(nanafy_section_file_size(NANAFY_TEXT_SECTION, &nana) == 1);
	// *put
	test(put_nanafy_section(1, NANAFY_DATA_SECTION, &nana) == NANAFY_SUCCESS);
	test(tell_nanafy_section(NANAFY_DATA_SECTION, &nana) == 1);
	test(nanafy_section_memory_size(NANAFY_DATA_SECTION, &nana) == 1);
	test(nanafy_section_file_size(NANAFY_DATA_SECTION, &nana) == 1);
	// *put
	test(put_nanafy_section(1, NANAFY_RODATA_SECTION, &nana) == NANAFY_SUCCESS);
	test(tell_nanafy_section(NANAFY_RODATA_SECTION, &nana) == 1);
	test(nanafy_section_memory_size(NANAFY_RODATA_SECTION, &nana) == 1);
	test(nanafy_section_file_size(NANAFY_RODATA_SECTION, &nana) == 1);
	// *put
	test(put_nanafy_section(1, NANAFY_BSS_SECTION, &nana) != NANAFY_SUCCESS); // always fail!
	test(tell_nanafy_section(NANAFY_BSS_SECTION, &nana) == 0);
	test(nanafy_section_memory_size(NANAFY_BSS_SECTION, &nana) == 0);
	test(nanafy_section_file_size(NANAFY_BSS_SECTION, &nana) == 0);
	// *write
	{
		char sequence[] = { 2, 3 };
		test(write_nanafy_section(sequence, sizeof(sequence), NANAFY_TEXT_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_TEXT_SECTION, &nana) == 3);
		test(nanafy_section_memory_size(NANAFY_TEXT_SECTION, &nana) == 3);
		test(nanafy_section_file_size(NANAFY_TEXT_SECTION, &nana) == 3);
	}
	// *write
	{
		char sequence[] = { 2, 3 };
		test(write_nanafy_section(sequence, sizeof(sequence), NANAFY_DATA_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_DATA_SECTION, &nana) == 3);
		test(nanafy_section_memory_size(NANAFY_DATA_SECTION, &nana) == 3);
		test(nanafy_section_file_size(NANAFY_DATA_SECTION, &nana) == 3);
	}
	// *write
	{
		char sequence[] = { 2, 3 };
		test(write_nanafy_section(sequence, sizeof(sequence), NANAFY_RODATA_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_RODATA_SECTION, &nana) == 3);
		test(nanafy_section_memory_size(NANAFY_RODATA_SECTION, &nana) == 3);
		test(nanafy_section_file_size(NANAFY_RODATA_SECTION, &nana) == 3);
	}
	// *write
	{
		char sequence[] = { 2, 3 };
		test(write_nanafy_section(sequence, sizeof(sequence), NANAFY_BSS_SECTION, &nana) != NANAFY_SUCCESS); // always fail!
		test(tell_nanafy_section(NANAFY_BSS_SECTION, &nana) == 0);
		test(nanafy_section_memory_size(NANAFY_BSS_SECTION, &nana) == 0);
		test(nanafy_section_file_size(NANAFY_BSS_SECTION, &nana) == 0);
	}
	// *allocate
	{
		test(allocate_nanafy_section(3, NANAFY_TEXT_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_TEXT_SECTION, &nana) == 6);
		test(nanafy_section_memory_size(NANAFY_TEXT_SECTION, &nana) == 6);
		test(nanafy_section_file_size(NANAFY_TEXT_SECTION, &nana) == 6);
	}
	// *allocate
	{
		test(allocate_nanafy_section(3, NANAFY_DATA_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_DATA_SECTION, &nana) == 6);
		test(nanafy_section_memory_size(NANAFY_DATA_SECTION, &nana) == 6);
		test(nanafy_section_file_size(NANAFY_DATA_SECTION, &nana) == 6);
	}
	// *allocate
	{
		test(allocate_nanafy_section(3, NANAFY_RODATA_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_RODATA_SECTION, &nana) == 6);
		test(nanafy_section_memory_size(NANAFY_RODATA_SECTION, &nana) == 6);
		test(nanafy_section_file_size(NANAFY_RODATA_SECTION, &nana) == 6);
	}
	// *allocate
	{
		test(allocate_nanafy_section(6, NANAFY_BSS_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_BSS_SECTION, &nana) == 6);
		test(nanafy_section_memory_size(NANAFY_BSS_SECTION, &nana) == 6);
		test(nanafy_section_file_size(NANAFY_BSS_SECTION, &nana) == 0);
	}
	// *align { 1, 2, 3, 0, 0, 0, 0, 0 }
	{
		test(align_nanafy_section(0, 8, NANAFY_TEXT_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_TEXT_SECTION, &nana) == 8);
		test(nanafy_section_memory_size(NANAFY_TEXT_SECTION, &nana) == 8);
		test(nanafy_section_file_size(NANAFY_TEXT_SECTION, &nana) == 8);
	}
	// *align { 1, 2, 3, 0, 0, 0, 0, 0 }
	{
		test(align_nanafy_section(0, 8, NANAFY_DATA_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_DATA_SECTION, &nana) == 8);
		test(nanafy_section_memory_size(NANAFY_DATA_SECTION, &nana) == 8);
		test(nanafy_section_file_size(NANAFY_DATA_SECTION, &nana) == 8);
	}
	// *align { 1, 2, 3, 0, 0, 0, 0, 0 }
	{
		test(align_nanafy_section(0, 8, NANAFY_RODATA_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_RODATA_SECTION, &nana) == 8);
		test(nanafy_section_memory_size(NANAFY_RODATA_SECTION, &nana) == 8);
		test(nanafy_section_file_size(NANAFY_RODATA_SECTION, &nana) == 8);
	}
	// *align 
	{
		test(align_nanafy_section(0, 8, NANAFY_BSS_SECTION, &nana) == NANAFY_SUCCESS);
		test(tell_nanafy_section(NANAFY_BSS_SECTION, &nana) == 8);
		test(nanafy_section_memory_size(NANAFY_BSS_SECTION, &nana) == 8);
		test(nanafy_section_file_size(NANAFY_BSS_SECTION, &nana) == 0);
	}
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_TEXT_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		test(buffer[0] == 1);
		test(buffer[1] == 2);
		test(buffer[2] == 3);
		test(buffer[3] == 0);
		test(buffer[4] == 0);
		test(buffer[5] == 0);
		test(buffer[6] == 0);
		test(buffer[7] == 0);
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 8, NANAFY_TEXT_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_DATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		test(buffer[0] == 1);
		test(buffer[1] == 2);
		test(buffer[2] == 3);
		test(buffer[3] == 0);
		test(buffer[4] == 0);
		test(buffer[5] == 0);
		test(buffer[6] == 0);
		test(buffer[7] == 0);
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 8, NANAFY_DATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_RODATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 8);
		test(buffer[0] == 1);
		test(buffer[1] == 2);
		test(buffer[2] == 3);
		test(buffer[3] == 0);
		test(buffer[4] == 0);
		test(buffer[5] == 0);
		test(buffer[6] == 0);
		test(buffer[7] == 0);
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 8, NANAFY_RODATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_section_product(buffer, sizeof(buffer), 0, NANAFY_BSS_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read all 
	{
		size_t offset = 0;
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_all_section_product(buffer, 8, offset, &nana, &readsize) == 0);
			test(readsize == 8);
			test(buffer[0] == 1);
			test(buffer[1] == 2);
			test(buffer[2] == 3);
			test(buffer[3] == 0);
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
			offset += readsize;
		}
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_all_section_product(buffer, 8, offset, &nana, &readsize) == 0);
			test(readsize == 8);
			test(buffer[0] == 1);
			test(buffer[1] == 2);
			test(buffer[2] == 3);
			test(buffer[3] == 0);
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
			offset += readsize;
		}
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_all_section_product(buffer, 8, offset, &nana, &readsize) == 0);
			test(readsize == 8);
			test(buffer[0] == 1);
			test(buffer[1] == 2);
			test(buffer[2] == 3);
			test(buffer[3] == 0);
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
			offset += readsize;
		}
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_all_section_product(buffer, 8, offset, &nana, &readsize) == 0);
			test(readsize == 0);
		}
	}
	// *read header
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), 0, NANAFY_TEXT_SECTION, &nana, &readsize) == 0);
		test(readsize == sizeof(isheader));
		test(isheader.Name[0] == '.');
		test(isheader.Name[1] == 't');
		test(isheader.Name[2] == 'e');
		test(isheader.Name[3] == 'x');
		test(isheader.Name[4] == 't');
		test(isheader.Name[5] == '\0');
		test(isheader.Characteristics & IMAGE_SCN_MEM_EXECUTE);
		test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
		//test(isheader.Misc.VirtualSize == 0);
		test(isheader.VirtualAddress == 0);
		test(isheader.SizeOfRawData == 8);
		test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4);
		test(isheader.PointerToRelocations == 0);
		test(isheader.NumberOfRelocations == 0);
		test(isheader.NumberOfLinenumbers == 0);
	}
	// *read eof
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), sizeof(isheader), NANAFY_TEXT_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read header
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), 0, NANAFY_DATA_SECTION, &nana, &readsize) == 0);
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
		test(isheader.VirtualAddress == 8); // after .text!
		test(isheader.SizeOfRawData == 8);
		test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4 + 8); // after .text!
		test(isheader.PointerToRelocations == 0);
		test(isheader.NumberOfRelocations == 0);
		test(isheader.NumberOfLinenumbers == 0);
	}
	// *read eof
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), sizeof(isheader), NANAFY_DATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read header
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), 0, NANAFY_RODATA_SECTION, &nana, &readsize) == 0);
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
		test(isheader.VirtualAddress == 16); // after .text and .data!
		test(isheader.SizeOfRawData == 8);
		test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4 + 16); // after .text and .data!
		test(isheader.PointerToRelocations == 0);
		test(isheader.NumberOfRelocations == 0);
		test(isheader.NumberOfLinenumbers == 0);
	}
	// *read eof
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), sizeof(isheader), NANAFY_RODATA_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read header
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), 0, NANAFY_BSS_SECTION, &nana, &readsize) == 0);
		test(readsize == sizeof(isheader));
		test(isheader.Name[0] == '.');
		test(isheader.Name[1] == 'b');
		test(isheader.Name[2] == 's');
		test(isheader.Name[3] == 's');
		test(isheader.Name[4] == '\0');
		test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
		test(isheader.Characteristics & IMAGE_SCN_MEM_WRITE);
		//test(isheader.Misc.VirtualSize == 0);
		test(isheader.VirtualAddress == 24); // after .text .data and .rodata!
		test(isheader.SizeOfRawData == 8);
		test(isheader.PointerToRawData == 0); // .bss has no pointer!
		test(isheader.PointerToRelocations == 0);
		test(isheader.NumberOfRelocations == 0);
		test(isheader.NumberOfLinenumbers == 0);
	}
	// *read eof
	{
		IMAGE_SECTION_HEADER isheader;
		size_t readsize;
		test(read_nanafy_image_section_header_product(&isheader, sizeof(isheader), sizeof(isheader), NANAFY_BSS_SECTION, &nana, &readsize) == 0);
		test(readsize == 0);
	}
	// *read all header 
	{
		size_t offset = 0;
		// *read header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_all_image_section_header_product(&isheader, sizeof(isheader), offset, &nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			test(isheader.Name[0] == '.');
			test(isheader.Name[1] == 't');
			test(isheader.Name[2] == 'e');
			test(isheader.Name[3] == 'x');
			test(isheader.Name[4] == 't');
			test(isheader.Name[5] == '\0');
			test(isheader.Characteristics & IMAGE_SCN_MEM_EXECUTE);
			test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
			//test(isheader.Misc.VirtualSize == 0);
			test(isheader.VirtualAddress == 0);
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4);
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += sizeof(isheader);
		}
		// *read header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_all_image_section_header_product(&isheader, sizeof(isheader), offset, &nana, &readsize) == 0);
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
			test(isheader.VirtualAddress == 8); // after .text!
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4 + 8); // after .text!
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += sizeof(isheader);
		}
		// *read header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_all_image_section_header_product(&isheader, sizeof(isheader), offset, &nana, &readsize) == 0);
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
			test(isheader.VirtualAddress == 16); // after .text and .data!
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_SECTION_HEADER) * 4 + 16); // after .text and .data!
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += sizeof(isheader);
		}
		// *read header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_all_image_section_header_product(&isheader, sizeof(isheader), offset, &nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			test(isheader.Name[0] == '.');
			test(isheader.Name[1] == 'b');
			test(isheader.Name[2] == 's');
			test(isheader.Name[3] == 's');
			test(isheader.Name[4] == '\0');
			test(isheader.Characteristics & IMAGE_SCN_MEM_READ);
			test(isheader.Characteristics & IMAGE_SCN_MEM_WRITE);
			//test(isheader.Misc.VirtualSize == 0);
			test(isheader.VirtualAddress == 24); // after .text .data and .rodata!
			test(isheader.SizeOfRawData == 8);
			test(isheader.PointerToRawData == 0); // .bss has no pointer!
			test(isheader.PointerToRelocations == 0);
			test(isheader.NumberOfRelocations == 0);
			test(isheader.NumberOfLinenumbers == 0);
			offset += sizeof(isheader);
		}
		// *read eof
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_all_image_section_header_product(&isheader, sizeof(isheader), offset, &nana, &readsize) == 0);
			test(readsize == 0);
		}
	}
}
