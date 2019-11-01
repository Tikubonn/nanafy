#include <nanafy.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>//test

int extend_nanafy_symname_table (size_t buffsize, size_t arraysize, nanafy_symname_table *table){
	size_t newbuffsize = nanafy_buffer_size(&(table->buffer)) + buffsize;
	void *newbuffseq = malloc(newbuffsize);
	if (newbuffseq == NULL){
		return 1;
	}
	size_t newarraysize = nanafy_size_array_length(&(table->array)) + arraysize;
	size_t *newarrayseq = malloc(sizeof(size_t) * newarraysize);
	if (newarrayseq == NULL){
		free(newbuffseq);
		return 1;
	}
	nanafy_symname_table newtable;
	init_nanafy_symname_table(newbuffseq, newbuffsize, newarrayseq, newarraysize, table->hashfunc, &newtable);
	if (copy_nanafy_symname_table(table, &newtable) != 0){
		free(newbuffseq);
		free(newarrayseq);
		return 1;
	}
	free_nanafy_symname_table(table);
	*table = newtable;
	return 0;
}
