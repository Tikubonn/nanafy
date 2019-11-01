#include <nanafy.h>
#include <stdlib.h>

void free_nanafy (nanafy *nana){
	free_nanafy_memory(&(nana->text_memory));
	free_nanafy_memory(&(nana->data_memory));
	free_nanafy_memory(&(nana->rodata_memory));
	free_nanafy_symbol_list(&(nana->symbol_list));
	free_nanafy_symname_table(&(nana->symname_table));
	free_nanafy_relocation_list(&(nana->text_relocation_list));
	free_nanafy_relocation_list(&(nana->data_relocation_list));
	free_nanafy_relocation_list(&(nana->rodata_relocation_list));
	free_nanafy_local_relocation_list(&(nana->local_relocation_list));
	free(nana);
}
