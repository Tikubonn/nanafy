#include <test.h>
#include <nanafy.h>

DECLARE_NANAFY_LIST(int, int);

#define LIST_LENGTH 3
#define LIST2_LENGTH 6
#define LIST3_LENGTH 2

void test_copy_nanafy_list (){
	int listseq[LIST_LENGTH];
	int list2seq[LIST2_LENGTH];
	int list3seq[LIST3_LENGTH];
	nanafy_int_list list;
	nanafy_int_list list2;
	nanafy_int_list list3;
	init_nanafy_int_list(listseq, LIST_LENGTH, &list);
	init_nanafy_int_list(list2seq, LIST2_LENGTH, &list2);
	init_nanafy_int_list(list3seq, LIST3_LENGTH, &list3);
	test(nanafy_int_list_length(&list) == 0);
	test(nanafy_int_list_length(&list2) == 0);
	test(nanafy_int_list_length(&list3) == 0);
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
	// *check
	test(has_nanafy_int_list_margin(1, &list) == false);
	test(nanafy_int_list_length(&list) == 3);
	// *get
	{
		int value;
		test(get_nanafy_int_list(0, &list, &value) == 0);
		test(value == 1);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(1, &list, &value) == 0);
		test(value == 2);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(2, &list, &value) == 0);
		test(value == 3);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(3, &list, &value) != 0); // always fail!
	}
	// *copy
	test(copy_nanafy_int_list(&list, &list2) == 0);
	test(copy_nanafy_int_list(&list, &list3) != 0); // always fail!
	test(nanafy_int_list_length(&list2) == 3);
	// *get
	{
		int value;
		test(get_nanafy_int_list(0, &list2, &value) == 0);
		test(value == 1);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(1, &list2, &value) == 0);
		test(value == 2);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(2, &list2, &value) == 0);
		test(value == 3);
	}
	// *get
	{
		int value;
		test(get_nanafy_int_list(3, &list2, &value) != 0); // always fail!
	}
}
