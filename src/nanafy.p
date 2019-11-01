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
