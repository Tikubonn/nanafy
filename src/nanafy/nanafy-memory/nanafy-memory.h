#include <stddef.h>

extern int put_nanafy_manually (int, nanafy_section, nanafy*);
#include <stddef.h>

extern int put_nanafy (int, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status write_nanafy_manually (void*, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern int write_nanafy (void*, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status align_nanafy_manually (int, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern int align_nanafy (int, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status allocate_nanafy_manually (size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern int allocate_nanafy (size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern size_t tell_nanafy (nanafy_section, nanafy*);
