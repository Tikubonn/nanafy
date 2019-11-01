#include <nanafy.h>
#include <stddef.h>

void find_nanafy_relocation_info (nanafy_relocation_type type, size_t width, nanafy_info *info, bool *foundp, nanafy_relocation_info *infop){
	for (size_t index = 0; index < info->relocation_info_count; index++){
		if (info->relocation_infos[index].type == type && 
				info->relocation_infos[index].relocation_width == width){
			*foundp = true;
			*infop = info->relocation_infos[index];
			return;
		}
	}
	*foundp = false;
	return;
}
