
export CFLAGS += -g -Wall
export rootdir := $(CURDIR)

build: .always
	make h -C src
	make dist/nanafy.h
	make lib -C src
	make dist/nanafy.lib
	make dll -C src
	make dist/nanafy.dll

test: build
	make test -C test

clean: .always
	make clean -C src

dist/nanafy.h: src/nanafy.h
	cp src/nanafy.h dist/nanafy.h

dist/nanafy.lib: src/nanafy.lib
	cp src/nanafy.lib dist/nanafy.lib

dist/nanafy.dll: src/nanafy.dll
	cp src/nanafy.dll dist/nanafy.dll

.always:
