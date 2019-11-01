#include <nanafy.h>
#include <stddef.h>

void init_nanafy (
	void *textseq,
	size_t textsize,
	void *dataseq,
	size_t datasize,
	void *rodataseq,
	size_t rodatasize,
	nanafy_symbol *symbolseq,
	size_t symbolsize,
	void *symnamebufferseq,
	size_t symnamebuffersize,
	size_t *symnamearrayseq,
	size_t symnamearraysize,
	nanafy_symname_table_hash_func hashfunc,
	nanafy_relocation *textrelocationseq,
	size_t textrelocationsize,
	nanafy_relocation *datarelocationseq,
	size_t datarelocationsize,
	nanafy_relocation *rodatarelocationseq,
	size_t rodatarelocationsize,
	nanafy_local_relocation *localrelocationseq,
	size_t localrelocationsize,
	nanafy_info *info,
	nanafy *nanafyp){
	init_nanafy_memory(textseq, textsize, &(nanafyp->text_memory));
	init_nanafy_memory(dataseq, datasize, &(nanafyp->data_memory));
	init_nanafy_memory(rodataseq, rodatasize, &(nanafyp->rodata_memory));
	init_nanafy_uninited_memory(&(nanafyp->bss_memory));
	init_nanafy_symbol_list(symbolseq, symbolsize, &(nanafyp->symbol_list));
	init_nanafy_symname_table(symnamebufferseq, symnamebuffersize, symnamearrayseq, symnamearraysize, hashfunc, &(nanafyp->symname_table));
	init_nanafy_relocation_list(textrelocationseq, textrelocationsize, &(nanafyp->text_relocation_list));
	init_nanafy_relocation_list(datarelocationseq, datarelocationsize, &(nanafyp->data_relocation_list));
	init_nanafy_relocation_list(rodatarelocationseq, rodatarelocationsize, &(nanafyp->rodata_relocation_list));
	init_nanafy_local_relocation_list(localrelocationseq, localrelocationsize, &(nanafyp->local_relocation_list));
	nanafyp->info = *info;
}
