#include <stddef.h>

extern void init_nanafy_local_relocation (nanafy_section, size_t, size_t, size_t, nanafy_local_relocation*);
#include <stddef.h>

extern int fix_nanafy_memory_with_local_relocation (nanafy_local_relocation*, nanafy*);
#include <stdbool.h>

extern bool same_nanafy_local_relocation_placep (nanafy_local_relocation*, nanafy_local_relocation*);
