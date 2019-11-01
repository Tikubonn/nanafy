
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	nanafy.h
	rm -f compiled/test-nanafy-uninited-memory.o

test:
	make nanafy-uninited-memory.exe
	./nanafy-uninited-memory.exe

nanafy-uninited-memory.exe: main.c compiled/test-nanafy-uninited-memory.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-uninited-memory.o -lnanafy -o nanafy-uninited-memory.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-uninited-memory.o: src/test-nanafy-uninited-memory.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-nanafy-uninited-memory.c -o compiled/test-nanafy-uninited-memory.o
