#include "src/test-nanafy-symname-table.h"
#include "src/test-copy-nanafy-symname-table.h"
#include "src/test-extend-nanafy-symname-table.h"

int main (){
	test_nanafy_symname_table();
	test_copy_nanafy_symname_table();
	test_extend_nanafy_symname_table();
	return 0;
}
