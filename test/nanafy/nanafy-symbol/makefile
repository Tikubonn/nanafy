
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-symbol.o

test:
	make nanafy-symbol.exe
	./nanafy-symbol.exe

nanafy-symbol.exe: main.c compiled/test-nanafy-symbol.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-symbol.o -lnanafy -o nanafy-symbol.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-symbol.o: src/test-nanafy-symbol.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-symbol.c -o compiled/test-nanafy-symbol.o 
