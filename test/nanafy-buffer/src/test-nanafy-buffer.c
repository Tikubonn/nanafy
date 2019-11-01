#include <test.h>
#include <nanafy.h>

#define BUFFER_SIZE 8

void test_nanafy_buffer (){
	char bufferseq[BUFFER_SIZE];
	nanafy_buffer buffer;
	init_nanafy_buffer(bufferseq, BUFFER_SIZE, &buffer);
	test(tell_nanafy_buffer(&buffer) == 0);
	test(nanafy_buffer_size(&buffer) == BUFFER_SIZE);
	test(has_nanafy_buffer_margin(1, &buffer) == true);
	test(put_nanafy_buffer('a', &buffer) == 0);
	test(tell_nanafy_buffer(&buffer) == 1);
	test(has_nanafy_buffer_margin(1, &buffer) == true);
	test(put_nanafy_buffer('b', &buffer) == 0);
	test(tell_nanafy_buffer(&buffer) == 2);
	test(has_nanafy_buffer_margin(1, &buffer) == true);
	test(put_nanafy_buffer('c', &buffer) == 0);
	test(tell_nanafy_buffer(&buffer) == 3);
	test(has_nanafy_buffer_margin(1, &buffer) == true);
	test(put_nanafy_buffer('d', &buffer) == 0);
	test(tell_nanafy_buffer(&buffer) == 4);
	{
		char example[] = {'e', 'f', 'g', 'h'};
		test(has_nanafy_buffer_margin(sizeof(example), &buffer) == true);
		size_t wrotesize;
		write_nanafy_buffer(example, sizeof(example), &buffer, &wrotesize);
		test(wrotesize == sizeof(example));
		test(tell_nanafy_buffer(&buffer) == 8);
	}
	test(has_nanafy_buffer_margin(1, &buffer) == false); // always fail!
	test(put_nanafy_buffer('i', &buffer) != 0); // always fail!
	{
		char example[] = {'j', 'k', 'l', 'm'};
		test(has_nanafy_buffer_margin(sizeof(example), &buffer) == false); // always fail!
		size_t wrotesize;
		write_nanafy_buffer(example, sizeof(example), &buffer, &wrotesize);
		test(wrotesize != sizeof(example));
	}
	{
		char *bufferseq = nanafy_buffer_array(&buffer);
		char example[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
		for (size_t index = 0; index < 8; index++){
			test(bufferseq[index] == example[index]);
		}
	}
}
