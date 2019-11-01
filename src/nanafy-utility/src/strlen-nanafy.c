#include <stddef.h>

size_t strlen_nanafy (char *sequence){
	size_t count = 0;
	for (char *seq = sequence; *seq != '\0'; seq++){
		count++;
	}
	return count;
}
