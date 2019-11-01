#include <nanafy.h>
#include <windows.h>

static nanafy_relocation_info reloc_infos[] = {
	{ 
		NANAFY_RELATIVE_RELOCATION, 
		4, IMAGE_REL_I386_REL32
	},
	{
		NANAFY_ABSOLUTE_RELOCATION,
		4, IMAGE_REL_I386_DIR32 
	}
};

void setup_nanafy_info_for_x86 (nanafy_endian endian, nanafy_info *info){
	info->relocation_infos = reloc_infos;
	info->relocation_info_count = sizeof(reloc_infos) / sizeof(nanafy_relocation_info); // 2
	info->machine = IMAGE_FILE_MACHINE_I386;
	info->endian = endian;
}
