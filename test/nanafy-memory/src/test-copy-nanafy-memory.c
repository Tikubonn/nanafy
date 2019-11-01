#include <test.h>
#include <nanafy.h>

#define MEMORY_SIZE 4
#define MEMORY2_SIZE 8
#define MEMORY3_SIZE 2

void test_copy_nanafy_memory (){
	char memoryseq[MEMORY_SIZE];
	char memory2seq[MEMORY2_SIZE];
	char memory3seq[MEMORY3_SIZE];
	nanafy_memory memory;
	nanafy_memory memory2;
	nanafy_memory memory3;
	init_nanafy_memory(memoryseq, MEMORY_SIZE, &memory);
	init_nanafy_memory(memory2seq, MEMORY2_SIZE, &memory2);
	init_nanafy_memory(memory3seq, MEMORY3_SIZE, &memory3);
	// *put
	test(has_nanafy_memory_margin(1, &memory) == true);
	test(put_nanafy_memory('a', &memory) == 0);
	test(tell_nanafy_memory(&memory) == 1);
	test(sizeof_nanafy_memory_product(&memory) == 1);
	// *put
	test(has_nanafy_memory_margin(1, &memory) == true);
	test(put_nanafy_memory('b', &memory) == 0);
	test(tell_nanafy_memory(&memory) == 2);
	test(sizeof_nanafy_memory_product(&memory) == 2);
	// *put
	test(has_nanafy_memory_margin(1, &memory) == true);
	test(put_nanafy_memory('c', &memory) == 0);
	test(tell_nanafy_memory(&memory) == 3);
	test(sizeof_nanafy_memory_product(&memory) == 3);
	// *put
	test(has_nanafy_memory_margin(1, &memory) == true);
	test(put_nanafy_memory('d', &memory) == 0);
	test(tell_nanafy_memory(&memory) == 4);
	test(sizeof_nanafy_memory_product(&memory) == 4);
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 0, &memory, &readsize) == 0);
		test(readsize == 4);
		test(buffer[0] == 'a');
		test(buffer[1] == 'b');
		test(buffer[2] == 'c');
		test(buffer[3] == 'd');
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 4, &memory, &readsize) == 0);
		test(readsize == 0);
	}
	// *copy
	test(copy_nanafy_memory(&memory, &memory2) == 0);
	test(copy_nanafy_memory(&memory, &memory3) != 0); // always fail!
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 0, &memory2, &readsize) == 0);
		test(readsize == 4);
		test(buffer[0] == 'a');
		test(buffer[1] == 'b');
		test(buffer[2] == 'c');
		test(buffer[3] == 'd');
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 4, &memory2, &readsize) == 0);
		test(readsize == 0);
	}
}
