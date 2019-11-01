#include <nanafy.h>
#include <stddef.h>
#include <stdint.h>

void big_endian_nanafy (uintmax_t number, void *sequence, size_t size){
	for (size_t index = 0; index < size; index++){
		((uint8_t*)sequence)[index] = number & 0xff;
		number >>= 8;
	}
}
