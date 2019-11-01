#include <test.h>
#include <nanafy.h>

#define BUFFER_SIZE (9 + 9 + 4)
#define ARRAY_SIZE 3

#define EXAMPLE1 "example1"
#define EXAMPLE2 "example2"
#define EXAMPLE3 "example3"
#define A "a"
#define B "b"

void test_nanafy_symname_table (){
	char bufferseq[BUFFER_SIZE];
	size_t arrayseq[ARRAY_SIZE];
	nanafy_symname_table table;
	init_nanafy_symname_table(bufferseq, BUFFER_SIZE, arrayseq, ARRAY_SIZE, NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC, &table);
	// *add
	size_t example1index;
	test(add_nanafy_symname_table(EXAMPLE1, sizeof(EXAMPLE1) -1, &table, &example1index) == NANAFY_SUCCESS);
	// *add
	size_t example2index;
	test(add_nanafy_symname_table(EXAMPLE2, sizeof(EXAMPLE2) -1, &table, &example2index) == NANAFY_SUCCESS);
	// *add
	size_t example3index;
	test(add_nanafy_symname_table(EXAMPLE3, sizeof(EXAMPLE3) -1, &table, &example3index) == NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY); // always fail!
	// *add 
	size_t aindex;
	test(add_nanafy_symname_table(A, sizeof(A) -1, &table, &aindex) == NANAFY_SUCCESS);
	// *add 
	size_t bindex;
	test(add_nanafy_symname_table(B, sizeof(B) -1, &table, &bindex) == NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY); // always fail!
	// *find 
	{
		bool found;
		size_t foundindex;
		test(find_nanafy_symname_table(EXAMPLE1, sizeof(EXAMPLE1) -1, &table, &found, &foundindex) == 0);
		test(found == true);
		test(foundindex == example1index);
	}
	// *find 
	{
		bool found;
		size_t foundindex;
		test(find_nanafy_symname_table(EXAMPLE2, sizeof(EXAMPLE2) -1, &table, &found, &foundindex) == 0);
		test(found == true);
		test(foundindex == example2index);
	}
	// *find 
	{
		bool found;
		size_t foundindex;
		test(find_nanafy_symname_table(EXAMPLE3, sizeof(EXAMPLE3) -1, &table, &found, &foundindex) == 0);
		test(found == false); // always fail!
	}
	// *find 
	{
		bool found;
		size_t foundindex;
		test(find_nanafy_symname_table(A, sizeof(A) -1, &table, &found, &foundindex) == 0);
		test(found == true);
		test(foundindex == aindex);
	}
	// *find 
	{
		bool found;
		size_t foundindex;
		test(find_nanafy_symname_table(B, sizeof(B) -1, &table, &found, &foundindex) == 0);
		test(found == false); // always fail!
	}
	// *read
	{
		char buffer[1024];
		size_t offset = 0;
		// *read table size
		{
			DWORD tablesize;
			size_t readsize;
			test(read_nanafy_symname_table_product(&tablesize, sizeof(tablesize), offset, &table, &readsize) == 0);
			test(readsize == 4);
			test(tablesize == sizeof(EXAMPLE1) + sizeof(EXAMPLE2) + sizeof(A) +4);
			offset += readsize;
		}
		// *read
		{
			size_t readsize;
			test(read_nanafy_symname_table_product(buffer, sizeof(EXAMPLE1), offset, &table, &readsize) == 0);
			test(readsize == sizeof(EXAMPLE1));
			test_equal_string(buffer, EXAMPLE1);
			offset += readsize;
		}
		// *read
		{
			size_t readsize;
			test(read_nanafy_symname_table_product(buffer, sizeof(EXAMPLE2), offset, &table, &readsize) == 0);
			test(readsize == sizeof(EXAMPLE2));
			test_equal_string(buffer, EXAMPLE2);
			offset += readsize;
		}
		// *read
		{
			size_t readsize;
			test(read_nanafy_symname_table_product(buffer, sizeof(A), offset, &table, &readsize) == 0);
			test(readsize == sizeof(A));
			test_equal_string(buffer, A);
			offset += readsize;
		}
		// *read
		{
			size_t readsize;
			test(read_nanafy_symname_table_product(buffer, sizeof(buffer), offset, &table, &readsize) == 0);
			test(readsize == 0);
		}
	}
}
