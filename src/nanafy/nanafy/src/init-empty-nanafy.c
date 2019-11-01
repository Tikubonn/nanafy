#include <nanafy.h>

void init_empty_nanafy (nanafy_symname_table_hash_func hashfunc, nanafy_info *info, nanafy *nana){
	init_nanafy(
		NULL, 0,
		NULL, 0,
		NULL, 0,
		NULL, 0,
		NULL, 0,
		NULL, 0,
		hashfunc,
		NULL, 0,
		NULL, 0,
		NULL, 0,
		NULL, 0,
		info,
		nana
	);
}
