#include <nanafy.h>
#include <stddef.h>

int read_nanafy_symname_table_product (void *sequence, size_t size, size_t offset, nanafy_symname_table *table, size_t *readsizep){
	// *write symname table offset!
	if (offset < 4){
		size_t tablesize = tell_nanafy_buffer(&(table->buffer)) +4;
		size_t index;
		for (index = 0; index + offset < 4; index++){
			((char*)sequence)[index] = ((char*)&tablesize)[index + offset];
		}
		*readsizep = index;
		return 0;
	}
	// *write symname buffer
	else {
		size_t index;
		size_t off = offset -4;
		void *buffseq = nanafy_buffer_array(&(table->buffer));
		size_t buffsize = tell_nanafy_buffer(&(table->buffer));
		for (index = 0; index < size && off + index < buffsize; index++){
			((char*)sequence)[index] = ((char*)buffseq)[off + index];
		}
		*readsizep = index;
		return 0;
	}
}
