
default:

clean:
	rm -f nanafy.h
	rm -f nanafy.lib
	make clean -C nanafy-memory
	make clean -C nanafy-symbol
	make clean -C nanafy-relocation
	make clean -C nanafy
	make clean -C nanafy-local-relocation
	make clean -C nanafy-remap

h:
	make nanafy-memory.h -C nanafy-memory
	make nanafy-symbol.h -C nanafy-symbol
	make nanafy-relocation.h -C nanafy-relocation
	make nanafy.h -C nanafy
	make nanafy-local-relocation.h -C nanafy-local-relocation
	make nanafy-remap.h -C nanafy-remap
	make nanafy.h
	
lib:
	make nanafy-memory.lib -C nanafy-memory
	make nanafy-symbol.lib -C nanafy-symbol
	make nanafy-relocation.lib -C nanafy-relocation
	make nanafy.lib -C nanafy
	make nanafy-local-relocation.lib -C nanafy-local-relocation
	make nanafy-remap.lib -C nanafy-remap
	make nanafy.lib

nanafy.h: nanafy-memory/nanafy-memory.h nanafy-symbol/nanafy-symbol.h nanafy-relocation/nanafy-relocation.h nanafy/nanafy.h nanafy-local-relocation/nanafy-local-relocation.h nanafy-remap/nanafy-remap.h
	cat nanafy-memory/nanafy-memory.h nanafy-symbol/nanafy-symbol.h nanafy-relocation/nanafy-relocation.h nanafy/nanafy.h nanafy-local-relocation/nanafy-local-relocation.h nanafy-remap/nanafy-remap.h > nanafy.h

tempdir = $(shell mktemp -d)
workdir := $(CURDIR)

nanafy.lib: nanafy-memory/nanafy-memory.lib nanafy-symbol/nanafy-symbol.lib nanafy-relocation/nanafy-relocation.lib nanafy-local-relocation/nanafy-local-relocation.lib nanafy-remap/nanafy-remap.lib
	cd $(tempdir) && \
	ar x $(workdir)/nanafy-memory/nanafy-memory.lib && \
	ar x $(workdir)/nanafy-symbol/nanafy-symbol.lib && \
	ar x $(workdir)/nanafy-relocation/nanafy-relocation.lib && \
	ar x $(workdir)/nanafy/nanafy.lib && \
	ar x $(workdir)/nanafy-local-relocation/nanafy-local-relocation.lib && \
	ar x $(workdir)/nanafy-remap/nanafy-remap.lib && \
	ar r $(workdir)/nanafy.lib *.o
