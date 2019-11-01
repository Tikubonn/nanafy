#include <test.h>
#include <nanafy.h>

void test_nanafy_uninited_memory (){
	nanafy_uninited_memory memory;
	init_nanafy_uninited_memory(&memory);
	test(tell_nanafy_uninited_memory(&memory) == 0);
	test(sizeof_nanafy_uninited_memory_product(&memory) == 0);
	// *allocate
	allocate_nanafy_uninited_memory(4, &memory);
	test(tell_nanafy_uninited_memory(&memory) == 4);
	test(sizeof_nanafy_uninited_memory_product(&memory) == 0);
	// *allocate
	allocate_nanafy_uninited_memory(4, &memory);
	test(tell_nanafy_uninited_memory(&memory) == 8);
	test(sizeof_nanafy_uninited_memory_product(&memory) == 0);
	// *allocate
	allocate_nanafy_uninited_memory(4, &memory);
	test(tell_nanafy_uninited_memory(&memory) == 12);
	test(sizeof_nanafy_uninited_memory_product(&memory) == 0);
	// *align 
	align_nanafy_uninited_memory(8, &memory);
	test(tell_nanafy_uninited_memory(&memory) == 16);
	test(sizeof_nanafy_uninited_memory_product(&memory) == 0);
	// *read 
	{
		char buffer[1024];
		size_t readsize;
		read_nanafy_uninited_memory_product(buffer, sizeof(buffer), 0, &memory, &readsize);
		test(readsize == 0);
	}
}
