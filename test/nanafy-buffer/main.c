#include "src/test-nanafy-buffer.h"
#include "src/test-copy-nanafy-buffer.h"
#include "src/test-extend-nanafy-buffer.h"

int main (){
	test_nanafy_buffer();
	test_copy_nanafy_buffer();
	test_extend_nanafy_buffer();
	return 0;
}
