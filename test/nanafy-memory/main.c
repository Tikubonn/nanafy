#include "src/test-nanafy-memory.h"
#include "src/test-copy-nanafy-memory.h"
#include "src/test-extend-nanafy-memory.h"

int main (){
	test_nanafy_memory();
	test_copy_nanafy_memory();
	test_extend_nanafy_memory();
	return 0;
}
