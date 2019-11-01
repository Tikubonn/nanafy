#include <test.h>
#include <nanafy.h>

DECLARE_NANAFY_ARRAY(int, int); // declare nanafy_int_array!

#define ARRAY_LENGTH 8

void test_nanafy_array (){
	int arrayseq[ARRAY_LENGTH];
	nanafy_int_array array;
	init_nanafy_int_array(arrayseq, ARRAY_LENGTH, &array);
	test(nanafy_int_array_length(&array) == ARRAY_LENGTH);
	clear_nanafy_int_array(0, &array);
	// *set
	test(set_nanafy_int_array(1, 0, &array) == 0);
	test(set_nanafy_int_array(2, 1, &array) == 0);
	test(set_nanafy_int_array(3, 2, &array) == 0);
	test(set_nanafy_int_array(4, ARRAY_LENGTH, &array) != 0); // always fail!
	// *get
	{
		int value;
		test(get_nanafy_int_array(0, &array, &value) == 0);
		test(value == 1);
	}
	{
		int value;
		test(get_nanafy_int_array(1, &array, &value) == 0);
		test(value == 2);
	}
	{
		int value;
		test(get_nanafy_int_array(2, &array, &value) == 0);
		test(value == 3);
	}
	{
		int value;
		test(get_nanafy_int_array(ARRAY_LENGTH, &array, &value) != 0); // always fail!
	}
	// *get
	for (size_t index = 4; index < ARRAY_LENGTH; index++){
		int value;
		test(get_nanafy_int_array(index, &array, &value) == 0);
		test(value == 0);
	}
}
