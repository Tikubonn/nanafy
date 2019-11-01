#include <stddef.h>
#include <stdbool.h>

bool strcmp_nanafy (char *sequence1, size_t size1, char *sequence2, size_t size2){
	if (size1 == size2){
		for (size_t index = 0; index < size1; index++){
			if (sequence1[index] != sequence2[index]){
				return false;
			}
		}
		return true;
	}
	return false;
}
