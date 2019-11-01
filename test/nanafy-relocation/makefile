
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-relocation.o

test:
	make nanafy-relocation.exe
	./nanafy-relocation.exe

nanafy-relocation.exe: main.c compiled/test-nanafy-relocation.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-relocation.o -lnanafy -o nanafy-relocation.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-relocation.o: src/test-nanafy-relocation.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-relocation.c -o compiled/test-nanafy-relocation.o
