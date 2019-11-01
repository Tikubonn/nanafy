#include <nanafy.h>

nanafy *make_empty_nanafy (nanafy_symname_table_hash_func hashfunc, nanafy_info *info){
	return make_nanafy(0, 0, 0, 0, 0, 0, hashfunc, 0, 0, 0, 0, info);
}
