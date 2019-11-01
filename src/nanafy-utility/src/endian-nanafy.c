#include <nanafy.h>
#include <stddef.h>
#include <stdint.h>

int endian_nanafy (uintmax_t number, nanafy_endian endian, void *sequence, size_t size){
	switch (endian){
		case NANAFY_BIG_ENDIAN:
			big_endian_nanafy(number, sequence, size);
			return 0;
		case NANAFY_LITTLE_ENDIAN:
			little_endian_nanafy(number, sequence, size);
			return 0;
		default:
			return 1;
	}
}
