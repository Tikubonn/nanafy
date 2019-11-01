#include <test.h>
#include <nanafy.h>

#define _MAIN "_main"
#define _RETURN0x45 "_return0x45"
#define _RETURN0x25 "_return0x25"

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
		test(register_nanafy_symbol(_MAIN, sizeof(_MAIN) -1, NANAFY_TEXT_SECTION, nana, &mainsymid) == 0);
		test(put_nanafy(0xe8, NANAFY_TEXT_SECTION, nana) == 0);
		size_t maincalloffset = tell_nanafy(NANAFY_TEXT_SECTION, nana);
		test(put_nanafy_offset(NANAFY_TEXT_SECTION, 0, 4, nana) == 0);
		test(put_nanafy(0xc3, NANAFY_TEXT_SECTION, nana) == 0);
		// *write return0x45
		size_t return0x45id;
		test(register_nanafy_symbol(_RETURN0x45, sizeof(_RETURN0x45) -1, NANAFY_TEXT_SECTION, nana, &return0x45id) == 0);
		//size_t return0x45offset = tell_nanafy(NANAFY_TEXT_SECTION, nana);//unused!
		{
			char codes[] = { 0xb8, 0x45, 0x00, 0x00, 0x00, 0xc3 };
			test(write_nanafy(codes, sizeof(codes), NANAFY_TEXT_SECTION, nana) == 0);
		}
		// *write return0x25
		size_t return0x25id;
		test(register_nanafy_symbol(_RETURN0x25, sizeof(_RETURN0x25) -1, NANAFY_TEXT_SECTION, nana, &return0x25id) == 0);
		size_t return0x25offset = tell_nanafy(NANAFY_TEXT_SECTION, nana);
		{
			char codes[] = { 0xb8, 0x25, 0x00, 0x00, 0x00, 0xc3 };
			test(write_nanafy(codes, sizeof(codes), NANAFY_TEXT_SECTION, nana) == 0);
		}
		// *rewrite main
		test(set_nanafy_offset(NANAFY_TEXT_SECTION, return0x25offset, maincalloffset, 4, nana) == 0);
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
		free_nanafy(nana);
	}
	test(fclose(file) == 0);
	return 0;
}
