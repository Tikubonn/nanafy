#include <test.h>
#include <nanafy.h>

DECLARE_NANAFY_LIST(int, int);

#define LIST_LENGTH 3

void test_nanafy_list (){
	int listseq[LIST_LENGTH];
	nanafy_int_list list;
	init_nanafy_int_list(listseq, LIST_LENGTH, &list);
	test(nanafy_int_list_length(&list) == 0);
	// *add
	{
		size_t index;
		test(has_nanafy_int_list_margin(1, &list) == true);
		test(add_nanafy_int_list(1, &list, &index) == 0);
		test(index == 0);
		test(nanafy_int_list_length(&list) == 1);
	}
	// *add
	{
		size_t index;
		test(has_nanafy_int_list_margin(1, &list) == true);
		test(add_nanafy_int_list(2, &list, &index) == 0);
		test(index == 1);
		test(nanafy_int_list_length(&list) == 2);
	}
	// *add
	{
		size_t index;
		test(has_nanafy_int_list_margin(1, &list) == true);
		test(add_nanafy_int_list(3, &list, &index) == 0);
		test(index == 2);
		test(nanafy_int_list_length(&list) == 3);
	}
	// *add
	{
		size_t index;
		test(has_nanafy_int_list_margin(1, &list) == false); // always fail!
		test(add_nanafy_int_list(4, &list, &index) != 0); // always fail!
	}
	// *set
	test(set_nanafy_int_list(10, 0, &list) == 0);
	test(set_nanafy_int_list(20, 1, &list) == 0);
	test(set_nanafy_int_list(30, 2, &list) == 0);
	test(set_nanafy_int_list(40, 3, &list) != 0); // always fail!
	// *get
	{
		int value;
		test(get_nanafy_int_list(0, &list, &value) == 0);
		test(value == 10);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(1, &list, &value) == 0);
		test(value == 20);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(2, &list, &value) == 0);
		test(value == 30);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(3, &list, &value) != 0); // always fail!
	}
}
