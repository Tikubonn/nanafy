#define DEFINE_NANAFY_ARRAY(name, type)\
DEFINE_INIT_NANAFY_ARRAY(name, type)\
DEFINE_SET_NANAFY_ARRAY(name, type)\
DEFINE_GET_NANAFY_ARRAY(name, type)\
DEFINE_NANAFY_ARRAY_LENGTH(name, type)\
DEFINE_CLEAR_NANAFY_ARRAY(name, type)\
DEFINE_COPY_NANAFY_ARRAY(name, type)\
DEFINE_EXTEND_NANAFY_ARRAY(name, type)\
DEFINE_FREE_NANAFY_ARRAY(name, type)

#define DECLARE_NANAFY_ARRAY(name, type)\
DEFINE_NANAFY_ARRAY_TYPE(name, type)\
DECLARE_INIT_NANAFY_ARRAY(name, type)\
DECLARE_SET_NANAFY_ARRAY(name, type)\
DECLARE_GET_NANAFY_ARRAY(name, type)\
DECLARE_NANAFY_ARRAY_LENGTH(name, type)\
DECLARE_CLEAR_NANAFY_ARRAY(name, type)\
DECLARE_COPY_NANAFY_ARRAY(name, type)\
DECLARE_EXTEND_NANAFY_ARRAY(name, type)\
DECLARE_FREE_NANAFY_ARRAY(name, type)
#include <stddef.h>

#define DEFINE_NANAFY_ARRAY_TYPE(name, type)\
typedef struct nanafy_ ## name ## _array {\
type *sequence;\
size_t size;\
} nanafy_ ## name ## _array;
#include <stddef.h>

#define DEFINE_INIT_NANAFY_ARRAY(name, type)\
void init_nanafy_ ## name ## _array(type *sequence, size_t size, nanafy_ ## name ## _array *array){\
array->sequence = sequence;\
array->size = size;\
}

#define DECLARE_INIT_NANAFY_ARRAY(name, type)\
extern void init_nanafy_ ## name ## _array(type*, size_t, nanafy_ ## name ## _array*);
#include <stddef.h>

#define DEFINE_GET_NANAFY_ARRAY(name, type)\
int get_nanafy_ ## name ## _array(size_t index, nanafy_ ## name ## _array *array, type *valuep){\
if (index < array->size){\
*valuep = array->sequence[index];\
return 0;\
}\
return 1;\
}

#define DECLARE_GET_NANAFY_ARRAY(name, type)\
extern int get_nanafy_ ## name ## _array(size_t, nanafy_ ## name ## _array*, type*);
#include <stddef.h>

#define DEFINE_SET_NANAFY_ARRAY(name, type)\
int set_nanafy_ ## name ## _array(type value, size_t index, nanafy_ ## name ## _array *array){\
if (index < array->size){\
array->sequence[index] = value;\
return 0;\
}\
return 1;\
}

#define DECLARE_SET_NANAFY_ARRAY(name, type)\
extern int set_nanafy_ ## name ## _array(type, size_t, nanafy_ ## name ## _array*);
#include <stddef.h>

#define DEFINE_NANAFY_ARRAY_LENGTH(name, type)\
size_t nanafy_ ## name ## _array_length(nanafy_ ## name ## _array *array){\
return array->size;\
}

#define DECLARE_NANAFY_ARRAY_LENGTH(name, type)\
extern size_t nanafy_ ## name ## _array_length(nanafy_ ## name ## _array*);
#include <stddef.h>

#define DEFINE_CLEAR_NANAFY_ARRAY(name, type)\
void clear_nanafy_ ## name ## _array(type value, nanafy_ ## name ## _array *array){\
for (size_t index = 0; index < array->size; index++){\
array->sequence[index] = value;\
}\
}

#define DECLARE_CLEAR_NANAFY_ARRAY(name, type)\
extern void clear_nanafy_ ## name ## _array(type, nanafy_ ## name ## _array*);
#include <stddef.h>

#define DEFINE_COPY_NANAFY_ARRAY(name, type)\
int copy_nanafy_ ## name ## _array(nanafy_ ## name ## _array *arrayfrom, nanafy_ ## name ## _array *arrayto){\
if (arrayfrom->size <= arrayto->size){\
for (size_t index = 0; index < arrayfrom->size; index++){\
arrayto->sequence[index] = arrayfrom->sequence[index];\
}\
return 0;\
}\
return 1;\
}

#define DECLARE_COPY_NANAFY_ARRAY(name, type)\
extern int copy_nanafy_ ## name ## _array(nanafy_ ## name ## _array*, nanafy_ ## name ## _array*);
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFINE_EXTEND_NANAFY_ARRAY(name, type)\
int extend_nanafy_ ## name ## _array(type defvalue, size_t exsize, nanafy_ ## name ## _array *array){\
size_t newsize = array->size + exsize;\
type *newseq = realloc(array->sequence, sizeof(type) * newsize);\
if (newseq == NULL){\
return 1;\
}\
else {\
for (size_t index = 0; index < exsize; index++){\
newseq[array->size + index] = defvalue;\
}\
array->sequence = newseq;\
array->size = newsize;\
return 0;\
}\
}

#define DECLARE_EXTEND_NANAFY_ARRAY(name, type)\
extern int extend_nanafy_ ## name ## _array(type, size_t, nanafy_ ## name ## _array*);
#include <stddef.h>
#include <stdlib.h>

#define DEFINE_FREE_NANAFY_ARRAY(name, type)\
void free_nanafy_ ## name ## _array(nanafy_ ## name ## _array *array){\
if (array->sequence != NULL){\
free(array->sequence);\
}\
}

#define DECLARE_FREE_NANAFY_ARRAY(name, type)\
extern void free_nanafy_ ## name ## _array(nanafy_ ## name ## _array*);
#define DEFINE_NANAFY_LIST(name, type)\
DEFINE_INIT_NANAFY_LIST(name, type)\
DEFINE_SET_NANAFY_LIST(name, type)\
DEFINE_GET_NANAFY_LIST(name, type)\
DEFINE_ADD_NANAFY_LIST(name, type)\
DEFINE_NANAFY_LIST_LENGTH(name, type)\
DEFINE_COPY_NANAFY_LIST(name, type)\
DEFINE_EXTEND_NANAFY_LIST(name, type)\
DEFINE_FREE_NANAFY_LIST(name, type)\
DEFINE_HAS_NANAFY_LIST_MARGIN(name, type)

#define DECLARE_NANAFY_LIST(name, type)\
DEFINE_NANAFY_LIST_TYPE(name, type)\
DECLARE_INIT_NANAFY_LIST(name, type)\
DECLARE_SET_NANAFY_LIST(name, type)\
DECLARE_GET_NANAFY_LIST(name, type)\
DECLARE_ADD_NANAFY_LIST(name, type)\
DECLARE_NANAFY_LIST_LENGTH(name, type)\
DECLARE_COPY_NANAFY_LIST(name, type)\
DECLARE_EXTEND_NANAFY_LIST(name, type)\
DECLARE_FREE_NANAFY_LIST(name, type)\
DECLARE_HAS_NANAFY_LIST_MARGIN(name, type)
#include <stddef.h>

#define DEFINE_NANAFY_LIST_TYPE(name, type)\
typedef struct nanafy_ ## name ## _list {\
type *sequence;\
size_t seek;\
size_t size;\
} nanafy_ ## name ## _list;
#include <stddef.h>

#define DEFINE_INIT_NANAFY_LIST(name, type)\
void init_nanafy_ ## name ## _list (type *sequence, size_t size, nanafy_ ## name ## _list *list){\
list->sequence = sequence;\
list->seek = 0;\
list->size = size;\
}

#define DECLARE_INIT_NANAFY_LIST(name, type)\
extern void init_nanafy_ ## name ## _list (type*, size_t, nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_GET_NANAFY_LIST(name, type)\
int get_nanafy_ ## name ## _list (size_t index, nanafy_ ## name ## _list *list, type *valuep){\
if (index < list->seek){\
*valuep = list->sequence[index];\
return 0;\
}\
return 1;\
}

#define DECLARE_GET_NANAFY_LIST(name, type)\
extern int get_nanafy_ ## name ## _list (size_t, nanafy_ ## name ## _list*, type*);
#include <stddef.h>

#define DEFINE_SET_NANAFY_LIST(name, type)\
int set_nanafy_ ## name ## _list (type value, size_t index, nanafy_ ## name ## _list *list){\
if (index < list->seek){\
list->sequence[index] = value;\
return 0;\
}\
return 1;\
}

#define DECLARE_SET_NANAFY_LIST(name, type)\
extern int set_nanafy_ ## name ## _list (type, size_t, nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_ADD_NANAFY_LIST(name, type)\
int add_nanafy_ ## name ## _list (type value, nanafy_ ## name ## _list *list, size_t *indexp){\
if (list->seek < list->size){\
*indexp = list->seek;\
list->sequence[list->seek] = value;\
list->seek += 1;\
return 0;\
}\
return 1;\
}

#define DECLARE_ADD_NANAFY_LIST(name, type)\
extern int add_nanafy_ ## name ## _list (type, nanafy_ ## name ## _list*, size_t*);
#include <stddef.h>

#define DEFINE_NANAFY_LIST_LENGTH(name, type)\
size_t nanafy_ ## name ## _list_length (nanafy_ ## name ## _list *list){\
return list->seek;\
}

#define DECLARE_NANAFY_LIST_LENGTH(name, type)\
extern size_t nanafy_ ## name ## _list_length (nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_COPY_NANAFY_LIST(name, type)\
int copy_nanafy_ ## name ## _list (nanafy_ ## name ## _list *listfrom, nanafy_ ## name ## _list *listto){\
if (listfrom->seek <= listto->size){\
for (size_t index = 0; index < listfrom->seek; index++){\
listto->sequence[index] = listfrom->sequence[index];\
}\
listto->seek = listfrom->seek;\
return 0;\
}\
return 1;\
}

#define DECLARE_COPY_NANAFY_LIST(name, type)\
extern int copy_nanafy_ ## name ## _list (nanafy_ ## name ## _list*, nanafy_ ## name ## _list*);
#include <stddef.h>

#define DEFINE_EXTEND_NANAFY_LIST(name, type)\
int extend_nanafy_ ## name ## _list (size_t exsize, nanafy_ ## name ## _list *list){\
size_t newsize = list->size + exsize;\
type *newseq = realloc(list->sequence, sizeof(type) * newsize);\
if (newseq == NULL){\
return 1;\
}\
else {\
list->sequence = newseq;\
list->size = newsize;\
return 0;\
}\
}

#define DECLARE_EXTEND_NANAFY_LIST(name, type)\
extern int extend_nanafy_ ## name ## _list (size_t, nanafy_ ## name ## _list*);
#include <stddef.h>
#include <stdlib.h>

#define DEFINE_FREE_NANAFY_LIST(name, type)\
void free_nanafy_ ## name ## _list (nanafy_ ## name ## _list *list){\
if (list->sequence != NULL){\
free(list->sequence);\
}\
}

#define DECLARE_FREE_NANAFY_LIST(name, type)\
extern void free_nanafy_ ## name ## _list (nanafy_ ## name ## _list*);
#include <stddef.h>
#include <stdbool.h>

#define DEFINE_HAS_NANAFY_LIST_MARGIN(name, type)\
bool has_nanafy_ ## name ## _list_margin (size_t size, nanafy_ ## name ## _list *list){\
return list->seek + size <= list->size;\
}

#define DECLARE_HAS_NANAFY_LIST_MARGIN(name, type)\
extern bool has_nanafy_ ## name ## _list_margin (size_t, nanafy_ ## name ## _list*);
#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <windows.h>

typedef enum nanafy_section {
	NANAFY_NONE_SECTION,
	NANAFY_TEXT_SECTION,
	NANAFY_DATA_SECTION,
	NANAFY_RODATA_SECTION,
	NANAFY_BSS_SECTION,
} nanafy_section;

typedef enum nanafy_status {
	NANAFY_SUCCESS,
	NANAFY_ERROR,
	NANAFY_TEXT_MEMORY_NOT_ENOUGH_MEMORY,
	NANAFY_DATA_MEMORY_NOT_ENOUGH_MEMORY,
	NANAFY_RODATA_MEMORY_NOT_ENOUGH_MEMORY,
	NANAFY_BSS_MEMORY_NOT_ENOUGH_MEMORY,
	NANAFY_SYMNAME_TABLE_BUFFER_NOT_ENOUGH_MEMORY,
	NANAFY_SYMNAME_TABLE_ARRAY_NOT_ENOUGH_MEMORY,
	NANAFY_SYMBOL_LIST_NOT_ENOUGH_MEMORY,
	NANAFY_LOCAL_RELOCATION_LIST_NOT_ENOUGH_MEMORY,
	NANAFY_TEXT_RELOCATION_LIST_NOT_ENOUGH_MEMORY,
	NANAFY_DATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY,
	NANAFY_RODATA_RELOCATION_LIST_NOT_ENOUGH_MEMORY,
} nanafy_status;

typedef struct nanafy_buffer {
	void *sequence;
	size_t seek;
	size_t size;
} nanafy_buffer;

typedef struct nanafy_memory {
	nanafy_buffer buffer;
} nanafy_memory;

typedef struct nanafy_uninited_memory {
	size_t seek;
} nanafy_uninited_memory;

DECLARE_NANAFY_ARRAY(size, size_t);

#define NANAFY_SYMNAME_TABLE_EMPTY ((size_t)(~0))

typedef size_t (*nanafy_symname_table_hash_func)(char*, size_t);

typedef struct nanafy_symname_table {
	nanafy_size_array array;
	nanafy_buffer buffer;
	nanafy_symname_table_hash_func hashfunc;
} nanafy_symname_table;

typedef enum nanafy_symbol_type {
	NANAFY_PUBLIC_SYMBOL, // static でない関数や変数など外部に公開されるシンボル
	NANAFY_EXTERNAL_SYMBOL, // _printf 等の外部定義されたシンボル
	NANAFY_PRIVATE_SYMBOL, // static 等で定義された非公開なグローバル変数など
} nanafy_symbol_type;

typedef struct nanafy_symbol {
	nanafy_symbol_type type;
	nanafy_section section;
	size_t offset;
	size_t symnameoffset;
} nanafy_symbol;

DECLARE_NANAFY_LIST(symbol, nanafy_symbol);

typedef enum nanafy_endian {
	NANAFY_LITTLE_ENDIAN,
	NANAFY_BIG_ENDIAN,
} nanafy_endian;

typedef enum nanafy_relocation_type {
	NANAFY_RELATIVE_RELOCATION,
	NANAFY_ABSOLUTE_RELOCATION,
} nanafy_relocation_type;

typedef struct nanafy_relocation_info {
	nanafy_relocation_type type;
	DWORD relocation_width;
	DWORD relocation_type;
} nanafy_relocation_info;

typedef enum nanafy_machine {
	NANAFY_X86_MACHINE,
	NANAFY_X64_MACHINE,
} nanafy_machine;

typedef struct nanafy_info {
	size_t relocation_info_count;
	nanafy_relocation_info *relocation_infos;
	DWORD machine;
	nanafy_endian endian;
} nanafy_info;

typedef struct nanafy_relocation {
	nanafy_relocation_type type;
	//nanafy_section section;
	size_t offset;
	size_t size;
	size_t symbolid;
} nanafy_relocation;

DECLARE_NANAFY_LIST(relocation, nanafy_relocation);

typedef struct nanafy_local_relocation {
	nanafy_section section;
	size_t offsetfrom;
	size_t offsetto;
	size_t size;
} nanafy_local_relocation;

DECLARE_NANAFY_LIST(local_relocation, nanafy_local_relocation);

typedef struct nanafy {
	nanafy_memory text_memory;
	nanafy_memory data_memory;
	nanafy_memory rodata_memory;
	nanafy_uninited_memory bss_memory;
	nanafy_symname_table symname_table;
	nanafy_symbol_list symbol_list;
	nanafy_relocation_list text_relocation_list;
	nanafy_relocation_list data_relocation_list;
	nanafy_relocation_list rodata_relocation_list;
	nanafy_local_relocation_list local_relocation_list;
	nanafy_info info;
} nanafy;
#include <stddef.h>

extern void init_nanafy_buffer (void*, size_t, nanafy_buffer*);
#include <stddef.h>

extern int put_nanafy_buffer (int, nanafy_buffer*);
#include <stddef.h>

extern void write_nanafy_buffer (void*, size_t, nanafy_buffer*, size_t*);
#include <stddef.h>

extern size_t tell_nanafy_buffer (nanafy_buffer*);
#include <stddef.h>
#include <stdbool.h>

extern bool has_nanafy_buffer_margin (size_t, nanafy_buffer*);
#include <stddef.h>

extern size_t nanafy_buffer_size (nanafy_buffer *buffer);

extern void *nanafy_buffer_array (nanafy_buffer*);
#include <stddef.h>

extern int copy_nanafy_buffer (nanafy_buffer*, nanafy_buffer*);
#include <stddef.h>

extern int extend_nanafy_buffer (size_t, nanafy_buffer*);
#include <stdlib.h>

extern void free_nanafy_buffer (nanafy_buffer*);
#include <stddef.h>

extern void init_nanafy_memory (void*, size_t, nanafy_memory*);
#include <stddef.h>

extern int put_nanafy_memory (int, nanafy_memory*);
#include <stddef.h>

extern int write_nanafy_memory (void*, size_t, nanafy_memory*);
#include <stddef.h>

extern size_t tell_nanafy_memory (nanafy_memory*);
#include <stddef.h>
#include <stdbool.h>

extern bool has_nanafy_memory_margin (size_t, nanafy_memory*);
#include <stddef.h>

extern int extend_nanafy_memory (size_t, nanafy_memory*);

extern void free_nanafy_memory (nanafy_memory*);
#include <stddef.h>

extern size_t sizeof_nanafy_memory_product (nanafy_memory*);
#include <stddef.h>

extern int read_nanafy_memory_product (void*, size_t, size_t, nanafy_memory*, size_t*);
#include <stddef.h>

extern int align_nanafy_memory (int, size_t, nanafy_memory*);
#include <stddef.h>

extern int set_nanafy_memory (int, size_t, nanafy_memory*);
#include <stddef.h>

extern int rewrite_nanafy_memory (void*, size_t, size_t, nanafy_memory*);

extern int copy_nanafy_memory (nanafy_memory*, nanafy_memory*);
#include <stddef.h>

extern void init_nanafy_uninited_memory (nanafy_uninited_memory*);
#include <stddef.h>

extern void allocate_nanafy_uninited_memory (size_t, nanafy_uninited_memory*);
#include <stddef.h>

extern void align_nanafy_uninited_memory (size_t, nanafy_uninited_memory*);
#include <stddef.h>

extern size_t tell_nanafy_uninited_memory (nanafy_uninited_memory*);
#include <stddef.h>

extern size_t sizeof_nanafy_uninited_memory_product (nanafy_uninited_memory*);
#include <stddef.h>

extern int read_nanafy_uninited_memory_product (void*, size_t, size_t, nanafy_uninited_memory*, size_t*);
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
#include <stddef.h>

extern nanafy_status add_nanafy_symname_table (char*, size_t, nanafy_symname_table*, size_t*);
#include <stddef.h>

extern int copy_nanafy_symname_table (nanafy_symname_table*, nanafy_symname_table*);
#include <stddef.h>

extern int extend_nanafy_symname_table (size_t, size_t, nanafy_symname_table*);
#include <stddef.h>

extern int find_nanafy_symname_table (char*, size_t, nanafy_symname_table*, bool*, size_t*);

extern void free_nanafy_symname_table (nanafy_symname_table*);
#include <stddef.h>

extern void init_nanafy_symname_table (
	void*,
	size_t,
	size_t*,
	size_t,
	nanafy_symname_table_hash_func,
	nanafy_symname_table*);
#include <stddef.h>

extern int read_nanafy_symname_table_product (void*, size_t, size_t, nanafy_symname_table*, size_t*);
#include <stddef.h>

extern size_t sizeof_nanafy_symname_table_product (nanafy_symname_table*);
#include <stddef.h>

extern size_t NANAFY_SYMNAME_TABLE_DEFAULT_HASH_FUNC (char*, size_t);
#include <stddef.h>
#include <stdbool.h>

extern void init_nanafy_symbol (nanafy_section, size_t, size_t, nanafy_symbol*);
#include <stddef.h>
#include <stdbool.h>

extern void init_nanafy_external_symbol (size_t, nanafy_symbol*);
#include <stddef.h>

extern size_t nanafy_symbol_symname_offset (nanafy_symbol*);
#include <stdbool.h>
#include <windows.h>

extern int setup_image_symbol_with_nanafy_symbol (nanafy_symbol*, nanafy*, IMAGE_SYMBOL*);
#include <stddef.h>
#include <windows.h>

extern size_t sizeof_nanafy_symbol_product (nanafy_symbol*);
#include <stddef.h>
#include <windows.h>

extern int read_nanafy_symbol_product (void*, size_t, size_t, nanafy_symbol*, nanafy*, size_t*);
#include <stddef.h>
#include <stdbool.h>

extern void init_nanafy_private_symbol (nanafy_section, size_t, size_t, nanafy_symbol*);
#include <stddef.h>

extern size_t sizeof_nanafy_symbol_list_product (nanafy_symbol_list*);
#include <stddef.h>

extern int read_nanafy_symbol_list_product (void*, size_t, size_t, nanafy_symbol_list*, nanafy*, size_t*);

extern void setup_nanafy_info_for_x86 (nanafy_endian, nanafy_info*);

extern void setup_nanafy_info_for_x64 (nanafy_endian, nanafy_info*);
#include <stddef.h>

extern void find_nanafy_relocation_info (nanafy_relocation_type, size_t, nanafy_info*, bool*, nanafy_relocation_info*);
#include <nanafy.h>

extern int setup_nanafy_info (nanafy_machine, nanafy_endian, nanafy_info*);
#include <stddef.h>

extern void init_nanafy_relative_relocation (size_t, size_t, size_t, nanafy_relocation*);
#include <stddef.h>
#include <windows.h>

extern int setup_image_relocation_with_nanafy_relocation (nanafy_section, nanafy_relocation*, nanafy*, IMAGE_RELOCATION*);
#include <stddef.h>

extern size_t sizeof_nanafy_relocation_product (nanafy_section, nanafy_relocation*);
#include <stddef.h>

extern int read_nanafy_relocation_product (void*, size_t, size_t, nanafy_section, nanafy_relocation*, nanafy*, size_t*);
#include <stddef.h>

extern void init_nanafy_relocation (size_t, size_t, size_t, nanafy_relocation*);
#include <stddef.h>

extern size_t sizeof_nanafy_relocation_list_product (nanafy_section, nanafy_relocation_list*);
#include <stddef.h>

extern int read_nanafy_relocation_list_product (void*, size_t, size_t, nanafy_section, nanafy_relocation_list*, nanafy*, size_t*);
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
#include <stddef.h>

extern void init_nanafy_local_relocation (nanafy_section, size_t, size_t, size_t, nanafy_local_relocation*);
#include <stddef.h>

extern int fix_nanafy_memory_with_local_relocation (nanafy_local_relocation*, nanafy*);
#include <stdbool.h>

extern bool same_nanafy_local_relocation_placep (nanafy_local_relocation*, nanafy_local_relocation*);
#include <stddef.h>

extern int find_nanafy_local_relocation_list (nanafy_local_relocation*, nanafy_local_relocation_list*, bool*, size_t*);
#include <stddef.h>

extern int fix_nanafy_memory_with_local_relocation_list (nanafy_local_relocation_list*, nanafy*);
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
#include <stddef.h>

extern nanafy_status register_nanafy_external_symbol_manually (char*, size_t, nanafy*, size_t*);
#include <stddef.h>

extern int register_nanafy_external_symbol (char*, size_t, nanafy*, size_t*);
#include <stddef.h>

extern nanafy_status register_nanafy_symbol_manually (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int register_nanafy_symbol (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern nanafy_status register_nanafy_private_symbol_manually (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int register_nanafy_private_symbol (char*, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern int put_nanafy_external_offset (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status put_nanafy_external_offset_manually (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>

extern int put_nanafy_external_relative_offset (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status put_nanafy_external_relative_offset_manually (size_t, nanafy_section, size_t, nanafy*);
#include <stddef.h>
#include <windows.h>

extern int setup_image_file_header_with_nanafy (nanafy*, IMAGE_FILE_HEADER*);
#include <stddef.h>

extern size_t sizeof_nanafy_image_file_header_product (nanafy*);
#include <stddef.h>

extern int read_nanafy_image_file_header_product (void*, size_t, size_t, nanafy*, size_t*);
#include <stddef.h>

extern void init_nanafy (
	void*,
	size_t,
	void*,
	size_t,
	void*,
	size_t,
	nanafy_symbol*,
	size_t,
	void*,
	size_t,
	size_t*,
	size_t,
	nanafy_symname_table_hash_func,
	nanafy_relocation*,
	size_t,
	nanafy_relocation*,
	size_t,
	nanafy_relocation*,
	size_t,
	nanafy_local_relocation*,
	size_t,
	nanafy_info*,
	nanafy*);
#include <stddef.h>

extern nanafy *make_nanafy (
	size_t,
	size_t,
	size_t,
	size_t,
	size_t,
	size_t,
	nanafy_symname_table_hash_func,
	size_t,
	size_t,
	size_t,
	size_t,
	nanafy_info*);
#include <stdlib.h>

extern void free_nanafy (nanafy*);
#include <stddef.h>

extern size_t sizeof_nanafy_product (nanafy*);
#include <stddef.h>

extern int read_nanafy_product (void*, size_t, size_t, nanafy*, size_t*);

extern void init_empty_nanafy (nanafy_symname_table_hash_func, nanafy_info*, nanafy*);
#include <nanafy.h>

extern nanafy *make_empty_nanafy (nanafy_symname_table_hash_func, nanafy_info*);
#include <stddef.h>

extern nanafy_status put_nanafy_offset_manually (nanafy_section, size_t, size_t, nanafy*);
#include <stddef.h>

extern int put_nanafy_offset (nanafy_section, size_t, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status set_nanafy_offset_manually (nanafy_section sectionfrom, size_t offsetfrom, size_t offsetto, size_t size, nanafy *nana);
#include <stddef.h>

extern int set_nanafy_offset (nanafy_section, size_t, size_t, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_data_memory (void *sequence, size_t size, nanafy *nana);
#include <stddef.h>

extern int remap_nanafy_local_relocation_list (nanafy_local_relocation*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_text_relocation_list (nanafy_relocation*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_rodata_memory (void*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_symbol_list (nanafy_symbol*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_symname_table (void*, size_t, size_t*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_text_memory (void*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_data_relocation_list (nanafy_relocation*, size_t, nanafy*);
#include <stddef.h>

extern int remap_nanafy_rodata_relocation_list (nanafy_relocation*, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status add_nanafy_section_relative_relocation (size_t, nanafy_section, size_t, size_t, nanafy*);
#include <stddef.h>

extern nanafy_status add_nanafy_section_relocation (size_t, nanafy_section, size_t, size_t, nanafy*);
#include <stddef.h>

extern size_t countof_nanafy_section_relocation_product (nanafy_section, nanafy*);
#include <stddef.h>

extern int read_nanafy_all_section_relocation_product (void*, size_t, size_t, nanafy*, size_t*);
#include <stddef.h>

extern int read_nanafy_section_relocation_product (void*, size_t, size_t, nanafy_section, nanafy*, size_t*);
#include <stddef.h>

extern size_t sizeof_nanafy_all_section_relocation_product (nanafy*);
#include <stddef.h>

extern size_t sizeof_nanafy_section_relocation_product (nanafy_section, nanafy*);
#include <stddef.h>

extern size_t offsetof_nanafy_section_relocation_product (nanafy_section, nanafy*);
#include <stddef.h>

extern nanafy_status has_nanafy_section_relocation_margin (size_t, nanafy_section, nanafy*);
