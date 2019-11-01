#include <nanafy.h>
#include <stddef.h>
#include <stdint.h>

void little_endian_nanafy (uintmax_t number, void *sequence, size_t size){
	uintmax_t bnumber;
	big_endian_nanafy(number, &bnumber, sizeof(bnumber));
	for (size_t index = 0; index < size; index++){
		((uint8_t*)sequence)[index] = 0;
	}
	for (size_t index = 0; index < size && index < sizeof(bnumber); index++){
		((uint8_t*)sequence)[size - (index +1)] = ((uint8_t*)&bnumber)[index];
	}
}
