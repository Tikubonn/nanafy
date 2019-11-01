
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-local-relocation-list.o

test:
	make nanafy-local-relocation-list.exe
	./nanafy-local-relocation-list.exe

nanafy-local-relocation-list.exe: main.c compiled/test-nanafy-local-relocation-list.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-local-relocation-list.o -lnanafy -o nanafy-local-relocation-list.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-local-relocation-list.o: src/test-nanafy-local-relocation-list.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-local-relocation-list.c -o compiled/test-nanafy-local-relocation-list.o
