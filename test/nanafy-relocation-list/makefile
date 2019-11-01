
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-relocation-list.o

test:
	make nanafy-relocation-list.exe
	./nanafy-relocation-list.exe

nanafy-relocation-list.exe: main.c compiled/test-nanafy-relocation-list.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-relocation-list.o -lnanafy -o nanafy-relocation-list.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-relocation-list.o: src/test-nanafy-relocation-list.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-relocation-list.c -o compiled/test-nanafy-relocation-list.o
