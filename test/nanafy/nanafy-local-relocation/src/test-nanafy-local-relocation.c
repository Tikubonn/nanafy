#include <test.h>
#include <nanafy.h>
#include <stddef.h>
#include <windows.h>

void test_nanafy_local_relocation (){
	nanafy_info nanainfo;
	setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
	nanafy *nana = make_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
	test(nana != NULL);
	// *put 
	test(put_nanafy_offset(NANAFY_TEXT_SECTION, 0, 4, nana) == 0);
	test(put_nanafy_offset(NANAFY_DATA_SECTION, 0, 4, nana) == 0);
	test(put_nanafy_offset(NANAFY_RODATA_SECTION, 0, 4, nana) == 0);
	// *put 
	test(put_nanafy_offset(NANAFY_TEXT_SECTION, 0, 4, nana) == 0);   // 0-(0+4)=-4
	test(put_nanafy_offset(NANAFY_DATA_SECTION, 0, 4, nana) == 0);   // 0-(0+4)=-4
	test(put_nanafy_offset(NANAFY_RODATA_SECTION, 0, 4, nana) == 0); // 0-(0+4)=-4
	// *set
	test(set_nanafy_offset(NANAFY_TEXT_SECTION, 8, 4, 4, nana) == 0);   // 8-(4+4)=0
	test(set_nanafy_offset(NANAFY_DATA_SECTION, 8, 4, 4, nana) == 0);   // 8-(4+4)=0
	test(set_nanafy_offset(NANAFY_RODATA_SECTION, 8, 4, 4, nana) == 0); // 8-(4+4)=0
	// *read
	{
		size_t offset = 0;
		// *read file header
		{
			IMAGE_FILE_HEADER ifheader;
			size_t readsize;
			test(read_nanafy_product(&ifheader, sizeof(ifheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(ifheader));
			offset += readsize;
		}
		// *read section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read section header
		{
			IMAGE_SECTION_HEADER isheader;
			size_t readsize;
			test(read_nanafy_product(&isheader, sizeof(isheader), offset, nana, &readsize) == 0);
			test(readsize == sizeof(isheader));
			offset += readsize;
		}
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			// -4
			test(buffer[0] == -4);
			test(buffer[1] == -1);
			test(buffer[2] == -1);
			test(buffer[3] == -1);
			// +0
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
		}
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			// -4
			test(buffer[0] == -4);
			test(buffer[1] == -1);
			test(buffer[2] == -1);
			test(buffer[3] == -1);
			// +0
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
		}
		// *read 
		{
			char buffer[1024];
			size_t readsize;
			test(read_nanafy_product(buffer, 8, offset, nana, &readsize) == 0);
			test(readsize == 8);
			// -4
			test(buffer[0] == -4);
			test(buffer[1] == -1);
			test(buffer[2] == -1);
			test(buffer[3] == -1);
			// +0
			test(buffer[4] == 0);
			test(buffer[5] == 0);
			test(buffer[6] == 0);
			test(buffer[7] == 0);
		}
	}
}
