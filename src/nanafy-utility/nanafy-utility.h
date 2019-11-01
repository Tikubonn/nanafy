#include <stddef.h>

extern size_t alignment_padding_nanafy (size_t, size_t);
#include <stddef.h>

extern size_t strlen_nanafy (char*);
#include <stddef.h>
#include <stdbool.h>

extern bool strcmp_nanafy (char*, size_t, char*, size_t);
#include <stddef.h>
#include <stdint.h>

extern void big_endian_nanafy (uintmax_t, void*, size_t);
#include <stddef.h>
#include <stdint.h>

extern void little_endian_nanafy (uintmax_t, void*, size_t);
#include <stddef.h>
#include <stdint.h>

extern int endian_nanafy (uintmax_t, nanafy_endian, void*, size_t);
