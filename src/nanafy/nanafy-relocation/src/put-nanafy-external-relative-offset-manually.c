#include <nanafy.h>
#include <stddef.h>

nanafy_status put_nanafy_external_relative_offset_manually (size_t symid, nanafy_section section, size_t size, nanafy *nana){
	nanafy_status status;
	status = has_nanafy_section_margin(size, section, nana);
	if (status != NANAFY_SUCCESS){
		return status;
	}
	status = has_nanafy_section_relocation_margin(1, section, nana);
	if (status != NANAFY_SUCCESS){
		return status;
	}
	size_t offset = tell_nanafy_section(section, nana);
	if (allocate_nanafy(size, section, nana) != NANAFY_SUCCESS){
		return NANAFY_ERROR; // unknown status!
	}
	if (add_nanafy_section_relative_relocation(symid, section, offset, size, nana) != 0){
		return NANAFY_ERROR;
	}
	return NANAFY_SUCCESS;
}
