#include <test.h>
#include <nanafy.h>

DECLARE_NANAFY_ARRAY(int, int); // declare nanafy_int_array!

#define ARRAY_LENGTH 8

void test_clear_nanafy_array (){
	int arrayseq[ARRAY_LENGTH];
	nanafy_int_array array;
	init_nanafy_int_array(arrayseq, ARRAY_LENGTH, &array);
	test(nanafy_int_array_length(&array) == ARRAY_LENGTH);
	// *set
	for (size_t index = 0; index < ARRAY_LENGTH; index++){
		test(set_nanafy_int_array(1, index, &array) == 0);
	}
	// *get
	for (size_t index = 0; index < ARRAY_LENGTH; index++){
		int value;
		test(get_nanafy_int_array(index, &array, &value) == 0);
		test(value == 1);
	}
	// *clear
	clear_nanafy_int_array(0, &array);
	// *get
	for (size_t index = 0; index < ARRAY_LENGTH; index++){
		int value;
		test(get_nanafy_int_array(index, &array, &value) == 0);
		test(value == 0);
	}
}
