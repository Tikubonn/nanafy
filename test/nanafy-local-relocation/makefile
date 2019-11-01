
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-local-relocation.o

test:
	make nanafy-local-relocation.exe
	./nanafy-local-relocation.exe

nanafy-local-relocation.exe: main.c compiled/test-nanafy-local-relocation.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-local-relocation.o -lnanafy -o nanafy-local-relocation.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-local-relocation.o: src/test-nanafy-local-relocation.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-local-relocation.c -o compiled/test-nanafy-local-relocation.o
