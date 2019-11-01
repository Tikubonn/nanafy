#include <test.h>
#include <nanafy.h>

#define MEMORY_SIZE 8

void test_extend_nanafy_memory (){
	char *memoryseq = malloc(MEMORY_SIZE);
	test(memoryseq != NULL);
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
	// *put 
	test(has_nanafy_memory_margin(1, &memory) == false);
	test(put_nanafy_memory('i', &memory) != 0); // always error!
	// *write
	{
		char example[] = { 'j', 'k', 'l', 'm' };
		test(has_nanafy_memory_margin(sizeof(example), &memory) == false);
		test(write_nanafy_memory(example, sizeof(example), &memory) != 0); // always error!
	}
	// *extend
	test(extend_nanafy_memory(8, &memory) == 0);
	// *put 
	test(has_nanafy_memory_margin(1, &memory) == true);
	test(put_nanafy_memory('i', &memory) == 0);
	test(tell_nanafy_memory(&memory) == 9);
	test(sizeof_nanafy_memory_product(&memory) == 9);
	// *write
	{
		char example[] = { 'j', 'k', 'l', 'm' };
		test(has_nanafy_memory_margin(sizeof(example), &memory) == true);
		test(write_nanafy_memory(example, sizeof(example), &memory) == 0);
		test(tell_nanafy_memory(&memory) == 13);
		test(sizeof_nanafy_memory_product(&memory) == 13);
	}
	// *read
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 0, &memory, &readsize) == 0);
		test(readsize == 13);
		test(buffer[0] == 'a');
		test(buffer[1] == 'b');
		test(buffer[2] == 'c');
		test(buffer[3] == 'd');
		test(buffer[4] == 'e');
		test(buffer[5] == 'f');
		test(buffer[6] == '\0');
		test(buffer[7] == '\0');
		test(buffer[8] == 'i');
		test(buffer[9] == 'j');
		test(buffer[10] == 'k');
		test(buffer[11] == 'l');
		test(buffer[12] == 'm');
	}
	// *read eof
	{
		char buffer[1024];
		size_t readsize;
		test(read_nanafy_memory_product(buffer, sizeof(buffer), 13, &memory, &readsize) == 0);
		test(readsize == 0);
	}
}
