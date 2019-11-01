#include <nanafy.h>

int setup_nanafy_info (nanafy_machine machine, nanafy_endian endian, nanafy_info *nanainfo){
	switch (machine){
		case NANAFY_X86_MACHINE:
			setup_nanafy_info_for_x86(endian, nanainfo);
			return 0;
		case NANAFY_X64_MACHINE:
			setup_nanafy_info_for_x64(endian, nanainfo);
			return 0;
		default:
			return 1;
	}
}
