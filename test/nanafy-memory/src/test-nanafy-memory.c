#include <test.h>
#include <nanafy.h>

#define MEMORY_SIZE 8

void test_nanafy_memory (){
	char memoryseq[MEMORY_SIZE];
	nanafy_memory memory;
	init_nanafy_memory(memoryseq, MEMORY_SIZE, &memory);
	test(tell_nanafy_memory(&memory) == 0);
	test(sizeof_nanafy_memory_product(&memory) == 0);
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
	// *write
	{
		char example[] = { 'd', 'e', 'f' };
		test(has_nanafy_memory_margin(sizeof(example), &memory) == true);
		test(write_nanafy_memory(example, sizeof(example), &memory) == 0);
		test(tell_nanafy_memory(&memory) == 6);
		test(sizeof_nanafy_memory_product(&memory) == 6);
	}
	// *align
	test(align_nanafy_memory('\0', 8, &memory) == 0);
	test(tell_nanafy_memory(&memory) == 8);
	test(sizeof_nanafy_memory_product(&memory) == 8);
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 0, &memory, &readsize) == 0);
		test(readsize == 8);
		test(buffer[0] == 'a');
		test(buffer[1] == 'b');
		test(buffer[2] == 'c');
		test(buffer[3] == 'd');
		test(buffer[4] == 'e');
		test(buffer[5] == 'f');
		test(buffer[6] == '\0');
		test(buffer[7] == '\0');
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 8, &memory, &readsize) == 0);
		test(readsize == 0);
	}
	// *set
	test(set_nanafy_memory('A', 0, &memory) == 0);
	test(set_nanafy_memory('B', 1, &memory) == 0);
	test(set_nanafy_memory('C', 2, &memory) == 0);
	// *rewrite
	{
		char example[] = { 'D', 'E', 'F' };
		test(rewrite_nanafy_memory(example, sizeof(example), 3, &memory) == 0);
	}
	// *put 
	test(has_nanafy_memory_margin(1, &memory) == false);
	test(put_nanafy_memory('i', &memory) != 0); // always error!
	// *write
	{
		char example[] = { 'j', 'k', 'l', 'm' };
		test(has_nanafy_memory_margin(sizeof(example), &memory) == false);
		test(write_nanafy_memory(example, sizeof(example), &memory) != 0); // always error!
	}
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 0, &memory, &readsize) == 0);
		test(readsize == 8);
		test(buffer[0] == 'A');
		test(buffer[1] == 'B');
		test(buffer[2] == 'C');
		test(buffer[3] == 'D');
		test(buffer[4] == 'E');
		test(buffer[5] == 'F');
		test(buffer[6] == '\0');
		test(buffer[7] == '\0');
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 8, &memory, &readsize) == 0);
		test(readsize == 0);
	}
}
