#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

void test_nanafy_relocation (){
	nanafy_info nanainfo;
	setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
	nanafy *nana = make_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
	test(nana != NULL);
	// *register
	size_t symid;
	{
		char symname[] = "external";
 		test(register_nanafy_external_symbol(symname, sizeof(symname) -1, nana, &symid) == 0);
	}
	// *put 
	test(put_nanafy_external_relative_offset(symid, NANAFY_TEXT_SECTION, 4, nana) == 0);
	test(put_nanafy_external_relative_offset(symid, NANAFY_DATA_SECTION, 4, nana) == 0);
	test(put_nanafy_external_relative_offset(symid, NANAFY_RODATA_SECTION, 4, nana) == 0);
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
		// *read image section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read image section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read image section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read image section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read text binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 4, offset, nana, &readsize) == 0);
			test(readsize == 4);
			// +0
			test(buffer[0] == 0);
			test(buffer[1] == 0);
			test(buffer[2] == 0);
			test(buffer[3] == 0);
			offset += readsize;
		}
		// *read data binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 4, offset, nana, &readsize) == 0);
			test(readsize == 4);
			// +0
			test(buffer[0] == 0);
			test(buffer[1] == 0);
			test(buffer[2] == 0);
			test(buffer[3] == 0);
			offset += readsize;
		}
		// *read rodata binary
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 4, offset, nana, &readsize) == 0);
			test(readsize == 4);
			// +0
			test(buffer[0] == 0);
			test(buffer[1] == 0);
			test(buffer[2] == 0);
			test(buffer[3] == 0);
			offset += readsize;
		}
		// *read relocation
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_product(&irelocation, sizeof(irelocation), offset, nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 0);
			test(irelocation.SymbolTableIndex == symid);
			test(irelocation.Type == IMAGE_REL_I386_REL32);
			offset += readsize;
		}
		// *read relocation
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_product(&irelocation, sizeof(irelocation), offset, nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 4);
			test(irelocation.SymbolTableIndex == symid);
			test(irelocation.Type == IMAGE_REL_I386_REL32);
			offset += readsize;
		}
		// *read relocation
		{
			IMAGE_RELOCATION irelocation;
			size_t readsize;
			test(read_nanafy_product(&irelocation, sizeof(irelocation), offset, nana, &readsize) == 0);
			test(readsize == sizeof(irelocation));
			test(irelocation.VirtualAddress == 8);
			test(irelocation.SymbolTableIndex == symid);
			test(irelocation.Type == IMAGE_REL_I386_REL32);
			offset += readsize;
		}
	}
	// *free
	free_nanafy(nana);
}
