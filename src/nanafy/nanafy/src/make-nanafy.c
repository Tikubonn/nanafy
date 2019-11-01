#include <nanafy.h>
#include <stddef.h>
#include <stdlib.h>

nanafy *make_nanafy (
	size_t textsize,
	size_t datasize,
	size_t rodatasize,
	size_t symbolsize,
	size_t symnamebuffersize,
	size_t symnamearraysize,
	nanafy_symname_table_hash_func hashfunc,
	size_t textrelocationsize,
	size_t datarelocationsize,
	size_t rodatarelocationsize,
	size_t localrelocationsize,
	nanafy_info *info){
	nanafy *nana = malloc(sizeof(nanafy));
	if (nana == NULL){
		return NULL;
	}
	void *textseq = NULL;
	if (0 < textsize){
		textseq = malloc(textsize);
		if (textseq == NULL){
			free(nana);
			return NULL;
		}
	}
	void *dataseq = NULL;
	if (0 < datasize){
		dataseq = malloc(datasize);
		if (dataseq == NULL){
			free(nana);
			free(textseq);
			return NULL;
		}
	}
	void *rodataseq = NULL;
	if (0 < rodatasize){
		rodataseq = malloc(rodatasize);
		if (rodataseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			return NULL;
		}
	}
	void *symbolseq = NULL;
	if (0 < symbolsize){
		symbolseq = malloc(sizeof(nanafy_symbol) * symbolsize);
		if (symbolseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			return NULL;
		}
	}
	void *symnamebufferseq = NULL;
	if (0 < symnamebuffersize){
		symnamebufferseq = malloc(symnamebuffersize);
		if (symnamebufferseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			free(symbolseq);
			return NULL;
		}
	}
	void *symnamearrayseq = NULL;
	if (0 < symnamearraysize){
		symnamearrayseq = malloc(sizeof(size_t) * symnamearraysize);
		if (symnamearrayseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			free(symbolseq);
			free(symnamebufferseq);
			return NULL;
		}
	}
	nanafy_relocation *textrelocationseq = NULL;
	if (0 < textrelocationsize){
		textrelocationseq = malloc(sizeof(nanafy_relocation) * textrelocationsize);
		if (textrelocationseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			free(symbolseq);
			free(symnamebufferseq);
			free(symnamearrayseq);
			return NULL;
		}
	}
	nanafy_relocation *datarelocationseq = NULL;
	if (0 < datarelocationsize){
		datarelocationseq = malloc(sizeof(nanafy_relocation) * datarelocationsize);
		if (datarelocationseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			free(symbolseq);
			free(symnamebufferseq);
			free(symnamearrayseq);
			free(textrelocationseq);
			return NULL;
		}
	}
	nanafy_relocation *rodatarelocationseq = NULL;
	if (0 < rodatarelocationsize){
		rodatarelocationseq = malloc(sizeof(nanafy_relocation) * rodatarelocationsize);
		if (rodatarelocationseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			free(symbolseq);
			free(symnamebufferseq);
			free(symnamearrayseq);
			free(textrelocationseq);
			free(datarelocationseq);
			return NULL;
		}
	}
	nanafy_local_relocation *localrelocationseq = NULL;
	if (0 < localrelocationsize){
		localrelocationseq = malloc(sizeof(nanafy_local_relocation) * localrelocationsize);
		if (localrelocationseq == NULL){
			free(nana);
			free(textseq);
			free(dataseq);
			free(rodataseq);
			free(symbolseq);
			free(symnamebufferseq);
			free(symnamearrayseq);
			free(textrelocationseq);
			free(datarelocationseq);
			free(rodatarelocationseq);
			return NULL;
		}
	}
	init_nanafy(
		textseq,
		textsize,
		dataseq,
		datasize,
		rodataseq,
		rodatasize,
		symbolseq,
		symbolsize,
		symnamebufferseq,
		symnamebuffersize,
		symnamearrayseq,
		symnamearraysize,
		hashfunc,
		textrelocationseq,
		textrelocationsize,
		datarelocationseq,
		datarelocationsize,
		rodatarelocationseq,
		rodatarelocationsize,
		localrelocationseq,
		localrelocationsize,
		info,
		nana
	);
	return nana;
}
