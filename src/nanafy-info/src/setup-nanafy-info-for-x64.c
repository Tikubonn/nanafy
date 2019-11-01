#include <nanafy.h>
#include <windows.h>

static nanafy_relocation_info reloc_infos[] = {
	{
		NANAFY_RELATIVE_RELOCATION,
		4, IMAGE_REL_AMD64_REL32
	},
	{
		NANAFY_ABSOLUTE_RELOCATION,
		4, IMAGE_REL_AMD64_ADDR32
	},
	{
		NANAFY_ABSOLUTE_RELOCATION,
		8, IMAGE_REL_AMD64_ADDR64
	}
};

void setup_nanafy_info_for_x64 (nanafy_endian endian, nanafy_info *info){
	info->relocation_infos = reloc_infos;
	info->relocation_info_count = sizeof(reloc_infos) / sizeof(nanafy_relocation_info); // 3
	info->machine = IMAGE_FILE_MACHINE_AMD64;
	info->endian = endian;
}
