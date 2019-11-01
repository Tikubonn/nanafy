
extern void setup_nanafy_info_for_x86 (nanafy_endian, nanafy_info*);

extern void setup_nanafy_info_for_x64 (nanafy_endian, nanafy_info*);
#include <stddef.h>

extern void find_nanafy_relocation_info (nanafy_relocation_type, size_t, nanafy_info*, bool*, nanafy_relocation_info*);
#include <nanafy.h>

extern int setup_nanafy_info (nanafy_machine, nanafy_endian, nanafy_info*);
