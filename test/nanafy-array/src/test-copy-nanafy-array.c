#include <test.h>
#include <nanafy.h>

DECLARE_NANAFY_ARRAY(int, int); // declare nanafy_int_array!

#define ARRAY_LENGTH 8
#define ARRAY2_LENGTH 16
#define ARRAY3_LENGTH 6 /* fail case! */

void test_copy_nanafy_array (){
	int arrayseq[ARRAY_LENGTH];
	int array2seq[ARRAY2_LENGTH];
	int array3seq[ARRAY3_LENGTH];
	nanafy_int_array array;
	nanafy_int_array array2;
	nanafy_int_array array3;
	init_nanafy_int_array(arrayseq, ARRAY_LENGTH, &array);
	init_nanafy_int_array(array2seq, ARRAY2_LENGTH, &array2);
	init_nanafy_int_array(array3seq, ARRAY3_LENGTH, &array3);
	test(nanafy_int_array_length(&array) == ARRAY_LENGTH);
	test(nanafy_int_array_length(&array2) == ARRAY2_LENGTH);
	test(nanafy_int_array_length(&array3) == ARRAY3_LENGTH);
	clear_nanafy_int_array(0, &array);
	clear_nanafy_int_array(0, &array2);
	clear_nanafy_int_array(0, &array3);
	// *set
	test(set_nanafy_int_array(1, 0, &array) == 0);
	test(set_nanafy_int_array(2, 1, &array) == 0);
	test(set_nanafy_int_array(3, 2, &array) == 0);
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
	// *get
	for (size_t index = 3; index < nanafy_int_array_length(&array); index++){
		int value;
		test(get_nanafy_int_array(index, &array, &value) == 0);
		test(value == 0);
	}
	// *clear
	test(copy_nanafy_int_array(&array, &array2) == 0);
	test(copy_nanafy_int_array(&array, &array3) != 0); // always fail!
	// *get
	{
		int value;
		test(get_nanafy_int_array(0, &array2, &value) == 0);
		test(value == 1);
	}
	{
		int value;
		test(get_nanafy_int_array(1, &array2, &value) == 0);
		test(value == 2);
	}
	{
		int value;
		test(get_nanafy_int_array(2, &array2, &value) == 0);
		test(value == 3);
	}
	// *get
	for (size_t index = 3; index < nanafy_int_array_length(&array); index++){
		int value;
		test(get_nanafy_int_array(index, &array, &value) == 0);
		test(value == 0);
	}
}
