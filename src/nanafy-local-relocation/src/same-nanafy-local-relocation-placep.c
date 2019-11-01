#include <nanafy.h>
#include <stdbool.h>

bool same_nanafy_local_relocation_placep (nanafy_local_relocation *relocation1, nanafy_local_relocation *relocation2){
	return 
		relocation1->section == relocation2->section && 
		relocation1->offsetto == relocation2->offsetto && 
		relocation1->size == relocation2->size;
}
