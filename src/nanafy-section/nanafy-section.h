#include <stddef.h>

extern nanafy_status align_nanafy_section (int, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status allocate_nanafy_section (size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status has_nanafy_section_margin (size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern size_t nanafy_section_file_offset (nanafy_section, nanafy*);
#include <stddef.h>

extern size_t nanafy_section_file_size (nanafy_section, nanafy*);
#include <stddef.h>

extern size_t nanafy_section_memory_offset (nanafy_section, nanafy*);
#include <stddef.h>

extern size_t nanafy_section_memory_size (nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status put_nanafy_section (int, nanafy_section, nanafy*);
#include <stddef.h>

extern int read_nanafy_all_image_section_header_product (void*, size_t, size_t, nanafy*, size_t*);
#include <stddef.h>

extern int read_nanafy_image_section_header_product (void*, size_t, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int read_nanafy_section_product (void*, size_t, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int set_nanafy_section (int, nanafy_section, size_t, nanafy*);
#include <stddef.h>
#include <windows.h>

extern int setup_image_section_header_with_nanafy_section (nanafy_section, nanafy*, IMAGE_SECTION_HEADER*);
#include <stddef.h>

extern size_t sizeof_nanafy_all_image_section_header_product (nanafy*);
#include <stddef.h>
#include <windows.h>

extern size_t sizeof_nanafy_image_section_header_product (nanafy_section, nanafy*);
#include <stddef.h>

extern size_t sizeof_nanafy_section_product (nanafy_section, nanafy*);
#include <stddef.h>

extern size_t tell_nanafy_section (nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status write_nanafy_section (void*, size_t, nanafy_section, nanafy*);
#include <stddef.h>

extern size_t sizeof_nanafy_all_section_product (nanafy*);
#include <stddef.h>

extern int read_nanafy_all_section_product (void*, size_t, size_t, nanafy*, size_t*);
#include <stddef.h>

extern size_t countof_nanafy_image_section_header_product (nanafy*);
#include <stddef.h>

extern size_t numberof_nanafy_image_section_header_product (nanafy_section);
