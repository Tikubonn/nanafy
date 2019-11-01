
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy.h
	compiled/nanafy-int-array.o
	compiled/test-nanafy-array.o
	compiled/test-clear-nanafy-array.o
	compiled/test-copy-nanafy-array.o
	compiled/test-extend-nanafy-array.o

test:
	make nanafy-array.exe
	./nanafy-array.exe

nanafy-array.exe: main.c compiled/nanafy-int-array.o compiled/test-nanafy-array.o compiled/test-extend-nanafy-array.o compiled/test-clear-nanafy-array.o compiled/test-copy-nanafy-array.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/nanafy-int-array.o compiled/test-nanafy-array.o compiled/test-extend-nanafy-array.o compiled/test-clear-nanafy-array.o compiled/test-copy-nanafy-array.o -lnanafy -o nanafy-array.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/nanafy-int-array.o: src/nanafy-int-array.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/nanafy-int-array.c -o compiled/nanafy-int-array.o

compiled/test-nanafy-array.o: src/test-nanafy-array.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-array.c -o compiled/test-nanafy-array.o

compiled/test-clear-nanafy-array.o: src/test-clear-nanafy-array.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-clear-nanafy-array.c -o compiled/test-clear-nanafy-array.o

compiled/test-copy-nanafy-array.o: src/test-copy-nanafy-array.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-copy-nanafy-array.c -o compiled/test-copy-nanafy-array.o

compiled/test-extend-nanafy-array.o: src/test-extend-nanafy-array.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-extend-nanafy-array.c -o compiled/test-extend-nanafy-array.o
