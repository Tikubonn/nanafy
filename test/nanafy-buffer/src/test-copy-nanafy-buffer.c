#include <test.h>
#include <nanafy.h>

#define BUFFER_SIZE 4
#define BUFFER2_SIZE 8
#define BUFFER3_SIZE 2

void test_copy_nanafy_buffer (){
	char bufferseq[BUFFER_SIZE];
	char buffer2seq[BUFFER2_SIZE];
	char buffer3seq[BUFFER3_SIZE];
	nanafy_buffer buffer;
	nanafy_buffer buffer2;
	nanafy_buffer buffer3;
	init_nanafy_buffer(bufferseq, BUFFER_SIZE, &buffer);
	init_nanafy_buffer(buffer2seq, BUFFER2_SIZE, &buffer2);
	init_nanafy_buffer(buffer3seq, BUFFER3_SIZE, &buffer3);
	test(nanafy_buffer_size(&buffer) == BUFFER_SIZE);
	test(nanafy_buffer_size(&buffer2) == BUFFER2_SIZE);
	test(nanafy_buffer_size(&buffer3) == BUFFER3_SIZE);
	test(tell_nanafy_buffer(&buffer) == 0);
	test(tell_nanafy_buffer(&buffer2) == 0);
	test(tell_nanafy_buffer(&buffer3) == 0);
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
	test(copy_nanafy_buffer(&buffer, &buffer2) == 0);
	test(copy_nanafy_buffer(&buffer, &buffer3) != 0); // always fail!
	{
		char example[] = { 'a', 'b', 'c', 'd' };
		char *bufferseq = nanafy_buffer_array(&buffer2);
		for (size_t index = 0; index < sizeof(example); index++){
			test(bufferseq[index] == example[index]);
		}
	}
}
