
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	nanafy.h
	rm -f compiled/test-nanafy-memory.o
	rm -f compiled/test-copy-nanafy-memory.o
	rm -f compiled/test-extend-nanafy-memory.o

test:
	make nanafy-memory.exe
	./nanafy-memory.exe

nanafy-memory.exe: main.c compiled/test-nanafy-memory.o compiled/test-copy-nanafy-memory.o compiled/test-extend-nanafy-memory.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-memory.o compiled/test-copy-nanafy-memory.o compiled/test-extend-nanafy-memory.o -lnanafy -o nanafy-memory.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-memory.o: src/test-nanafy-memory.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-nanafy-memory.c -o compiled/test-nanafy-memory.o

compiled/test-copy-nanafy-memory.o: src/test-copy-nanafy-memory.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-copy-nanafy-memory.c -o compiled/test-copy-nanafy-memory.o

compiled/test-extend-nanafy-memory.o: src/test-extend-nanafy-memory.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-extend-nanafy-memory.c -o compiled/test-extend-nanafy-memory.o
