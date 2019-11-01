
CFLAGS += -I$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f nanafy.lib
	rm -f nanafy.dll
	make clean -C nanafy-array
	make clean -C nanafy-buffer 
	make clean -C nanafy-memory 
	make clean -C nanafy-uninited-memory 
	make clean -C nanafy-utility
	make clean -C nanafy-size-array
	make clean -C nanafy-symname-table
	make clean -C nanafy-list
	make clean -C nanafy-symbol
	make clean -C nanafy-symbol-list
	make clean -C nanafy-info
	make clean -C nanafy-relocation
	make clean -C nanafy-relocation-list
	make clean -C nanafy-section
	make clean -C nanafy-local-relocation
	make clean -C nanafy-local-relocation-list
	make clean -C nanafy
	make clean -C nanafy-section-relocation

h:
	make nanafy-array.h -C nanafy-array
	make nanafy-buffer.h -C nanafy-buffer 
	make nanafy-memory.h -C nanafy-memory 
	make nanafy-uninited-memory.h -C nanafy-uninited-memory 
	make nanafy-utility.h -C nanafy-utility
	make nanafy-symname-table.h -C nanafy-symname-table
	make nanafy-list.h -C nanafy-list
	make nanafy-symbol.h -C nanafy-symbol
	make nanafy-symbol-list.h -C nanafy-symbol-list
	make nanafy-info.h -C nanafy-info
	make nanafy-relocation.h -C nanafy-relocation
	make nanafy-relocation-list.h -C nanafy-relocation-list
	make nanafy-section.h -C nanafy-section
	make nanafy-local-relocation.h -C nanafy-local-relocation
	make nanafy-local-relocation-list.h -C nanafy-local-relocation-list
	make h -C nanafy
	make nanafy-section-relocation.h -C nanafy-section-relocation
	make nanafy.h

lib:
	make nanafy-buffer.lib -C nanafy-buffer 
	make nanafy-memory.lib -C nanafy-memory 
	make nanafy-uninited-memory.lib -C nanafy-uninited-memory
	make nanafy-utility.lib -C nanafy-utility
	make nanafy-size-array.lib -C nanafy-size-array
	make nanafy-symname-table.lib -C nanafy-symname-table
	make nanafy-symbol.lib -C nanafy-symbol
	make nanafy-symbol-list.lib -C nanafy-symbol-list
	make nanafy-info.lib -C nanafy-info
	make nanafy-relocation.lib -C nanafy-relocation
	make nanafy-relocation-list.lib -C nanafy-relocation-list
	make nanafy-section.lib -C nanafy-section
	make nanafy-local-relocation.lib -C nanafy-local-relocation
	make nanafy-local-relocation-list.lib -C nanafy-local-relocation-list
	make lib -C nanafy
	make nanafy-section-relocation.lib -C nanafy-section-relocation
	make nanafy.lib

dll:
	make nanafy-buffer.lib -C nanafy-buffer 
	make nanafy-memory.lib -C nanafy-memory 
	make nanafy-uninited-memory.lib -C nanafy-uninited-memory
	make nanafy-utility.lib -C nanafy-utility
	make nanafy-size-array.lib -C nanafy-size-array
	make nanafy-symname-table.lib -C nanafy-symname-table
	make nanafy-symbol.lib -C nanafy-symbol
	make nanafy-symbol-list.lib -C nanafy-symbol-list
	make nanafy-info.lib -C nanafy-info
	make nanafy-relocation.lib -C nanafy-relocation
	make nanafy-relocation-list.lib -C nanafy-relocation-list
	make nanafy-section.lib -C nanafy-section
	make nanafy-local-relocation.lib -C nanafy-local-relocation
	make nanafy-local-relocation-list.lib -C nanafy-local-relocation-list
	make lib -C nanafy
	make nanafy-section-relocation.lib -C nanafy-section-relocation
	make nanafy.dll

nanafy.h: nanafy-array/nanafy-array.h nanafy-symbol/nanafy-symbol.h nanafy.p nanafy-buffer/nanafy-buffer.h nanafy-memory/nanafy-memory.h nanafy-uninited-memory/nanafy-uninited-memory.h nanafy-utility/nanafy-utility.h nanafy-symname-table/nanafy-symname-table.h nanafy-list/nanafy-list.h nanafy-symbol-list/nanafy-symbol-list.h nanafy-info/nanafy-info.h nanafy-relocation/nanafy-relocation.h nanafy-relocation-list/nanafy-relocation-list.h nanafy-section/nanafy-section.h nanafy-local-relocation/nanafy-local-relocation.h nanafy-local-relocation-list/nanafy-local-relocation-list.h nanafy/nanafy.h nanafy-section-relocation/nanafy-section-relocation.h
	cat nanafy-array/nanafy-array.h nanafy-list/nanafy-list.h nanafy.p nanafy-buffer/nanafy-buffer.h nanafy-memory/nanafy-memory.h nanafy-uninited-memory/nanafy-uninited-memory.h nanafy-utility/nanafy-utility.h nanafy-symname-table/nanafy-symname-table.h nanafy-symbol/nanafy-symbol.h nanafy-symbol-list/nanafy-symbol-list.h nanafy-info/nanafy-info.h nanafy-relocation/nanafy-relocation.h nanafy-relocation-list/nanafy-relocation-list.h nanafy-section/nanafy-section.h nanafy-local-relocation/nanafy-local-relocation.h nanafy-local-relocation-list/nanafy-local-relocation-list.h nanafy/nanafy.h nanafy-section-relocation/nanafy-section-relocation.h > nanafy.h

tempdir = $(shell mktemp -d)
workdir := $(CURDIR)

nanafy.lib: nanafy-buffer/nanafy-buffer.lib nanafy-memory/nanafy-memory.lib nanafy-uninited-memory/nanafy-uninited-memory.lib nanafy-utility/nanafy-utility.lib nanafy-size-array/nanafy-size-array.lib nanafy-symname-table/nanafy-symname-table.lib nanafy-symbol/nanafy-symbol.lib nanafy-symbol-list/nanafy-symbol-list.lib nanafy-info/nanafy-info.lib nanafy-relocation/nanafy-relocation.lib nanafy-relocation-list/nanafy-relocation-list.lib nanafy-section/nanafy-section.lib nanafy-local-relocation/nanafy-local-relocation.lib nanafy-local-relocation-list/nanafy-local-relocation-list.lib nanafy/nanafy.lib nanafy-section-relocation/nanafy-section-relocation.lib
	cd $(tempdir) && \
	ar x $(workdir)/nanafy-buffer/nanafy-buffer.lib && \
	ar x $(workdir)/nanafy-memory/nanafy-memory.lib && \
	ar x $(workdir)/nanafy-uninited-memory/nanafy-uninited-memory.lib && \
	ar x $(workdir)/nanafy-utility/nanafy-utility.lib && \
	ar x $(workdir)/nanafy-size-array/nanafy-size-array.lib && \
	ar x $(workdir)/nanafy-symname-table/nanafy-symname-table.lib && \
	ar x $(workdir)/nanafy-symbol/nanafy-symbol.lib && \
	ar x $(workdir)/nanafy-symbol-list/nanafy-symbol-list.lib && \
	ar x $(workdir)/nanafy-info/nanafy-info.lib && \
	ar x $(workdir)/nanafy-relocation/nanafy-relocation.lib && \
	ar x $(workdir)/nanafy-relocation-list/nanafy-relocation-list.lib && \
	ar x $(workdir)/nanafy-section/nanafy-section.lib && \
	ar x $(workdir)/nanafy-local-relocation/nanafy-local-relocation.lib && \
	ar x $(workdir)/nanafy-local-relocation-list/nanafy-local-relocation-list.lib && \
	ar x $(workdir)/nanafy/nanafy.lib && \
	ar x $(workdir)/nanafy-section-relocation/nanafy-section-relocation.lib && \
	ar r $(workdir)/nanafy.lib *.o

nanafy.dll: nanafy-buffer/nanafy-buffer.lib nanafy-memory/nanafy-memory.lib nanafy-uninited-memory/nanafy-uninited-memory.lib nanafy-utility/nanafy-utility.lib nanafy-size-array/nanafy-size-array.lib nanafy-symname-table/nanafy-symname-table.lib nanafy-symbol/nanafy-symbol.lib nanafy-symbol-list/nanafy-symbol-list.lib nanafy-info/nanafy-info.lib nanafy-relocation/nanafy-relocation.lib nanafy-relocation-list/nanafy-relocation-list.lib nanafy-section/nanafy-section.lib nanafy-local-relocation/nanafy-local-relocation.lib nanafy-local-relocation-list/nanafy-local-relocation-list.lib nanafy/nanafy.lib nanafy-section-relocation/nanafy-section-relocation.lib
	cd $(tempdir) && \
	ar x $(workdir)/nanafy-buffer/nanafy-buffer.lib && \
	ar x $(workdir)/nanafy-memory/nanafy-memory.lib && \
	ar x $(workdir)/nanafy-uninited-memory/nanafy-uninited-memory.lib && \
	ar x $(workdir)/nanafy-utility/nanafy-utility.lib && \
	ar x $(workdir)/nanafy-size-array/nanafy-size-array.lib && \
	ar x $(workdir)/nanafy-symname-table/nanafy-symname-table.lib && \
	ar x $(workdir)/nanafy-symbol/nanafy-symbol.lib && \
	ar x $(workdir)/nanafy-symbol-list/nanafy-symbol-list.lib && \
	ar x $(workdir)/nanafy-info/nanafy-info.lib && \
	ar x $(workdir)/nanafy-relocation/nanafy-relocation.lib && \
	ar x $(workdir)/nanafy-relocation-list/nanafy-relocation-list.lib && \
	ar x $(workdir)/nanafy-section/nanafy-section.lib && \
	ar x $(workdir)/nanafy-local-relocation/nanafy-local-relocation.lib && \
	ar x $(workdir)/nanafy-local-relocation-list/nanafy-local-relocation-list.lib && \
	ar x $(workdir)/nanafy/nanafy.lib && \
	ar x $(workdir)/nanafy-section-relocation/nanafy-section-relocation.lib && \
	gcc *.o -shared -o $(workdir)/nanafy.dll
