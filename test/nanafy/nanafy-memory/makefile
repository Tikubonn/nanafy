
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	rm -f compiled/test-nanafy-memory.o

test:
	make nanafy-memory.exe
	./nanafy-memory.exe

nanafy-memory.exe: main.c compiled/test-nanafy-memory.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-memory.o -lnanafy -o nanafy-memory.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-memory.o: src/test-nanafy-memory.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-memory.c -o compiled/test-nanafy-memory.o 
