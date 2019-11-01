
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-symbol-list.o

test:
	make nanafy-symbol-list.exe
	./nanafy-symbol-list.exe

nanafy-symbol-list.exe: main.c compiled/test-nanafy-symbol-list.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-symbol-list.o -lnanafy -o nanafy-symbol-list.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll
	
compiled/test-nanafy-symbol-list.o: src/test-nanafy-symbol-list.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-symbol-list.c -o compiled/test-nanafy-symbol-list.o
