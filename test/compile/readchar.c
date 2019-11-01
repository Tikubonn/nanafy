#include <test.h>
#include <nanafy.h>

#define _MAIN "_main"
#define _GETCHAR "_getchar"

int main (int argcount, char **args){
	test(2 <= argcount);
	FILE *file = fopen(args[1], "wb");
	{
		nanafy_info nanainfo;
		setup_nanafy_info_for_x86(NANAFY_BIG_ENDIAN, &nanainfo);
		nanafy *nana = make_empty_nanafy(NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &nanainfo);
		test(nana != NULL);
		// *write main
		size_t mainsymid;
		size_t getcharsymid;
		test(register_nanafy_symbol(_MAIN, sizeof(_MAIN) -1, NANAFY_TEXT_SECTION, nana, &mainsymid) == 0);
		test(register_nanafy_external_symbol(_GETCHAR, sizeof(_GETCHAR) -1, nana, &getcharsymid) == 0);
		{
			char code[] = {
				0x55, 0x89, 0xe5,
				0xe8
			};
			test(write_nanafy(code, sizeof(code), NANAFY_TEXT_SECTION, nana) == 0);
		}
		test(put_nanafy_external_relative_offset(getcharsymid, NANAFY_TEXT_SECTION, 4, nana) == 0);
		{
			char code[] = {
				0xc9, 
				0x83, 0xe8, 0x30, 
				0xc3
			};
			test(write_nanafy(code, sizeof(code), NANAFY_TEXT_SECTION, nana) == 0);
		}
		// *write to file
		{
			size_t offset = 0;
			while (1){
				char buffer[1024];
				size_t readsize;
				test(read_nanafy_product(buffer, sizeof(buffer), offset, nana, &readsize) == 0);
				if (0 < readsize){
					test(fwrite(buffer, sizeof(char), readsize, file) == readsize);
					offset += readsize;
				}
				else {
					break;
				}
			}
		}
		// *free
		free_nanafy(nana);
	}
	test(fclose(file) == 0);
	return 0;
}
