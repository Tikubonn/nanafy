#include "src/test-nanafy-array.h"
#include "src/test-clear-nanafy-array.h"
#include "src/test-copy-nanafy-array.h"
#include "src/test-extend-nanafy-array.h"

int main (){
	test_nanafy_array();
	test_clear_nanafy_array();
	test_copy_nanafy_array();
	test_extend_nanafy_array();
	return 0;
}
