
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	nanafy.h
	rm -f compiled/test-nanafy-buffer.o
	rm -f compiled/test-copy-nanafy-buffer.o
	rm -f compiled/test-extend-nanafy-buffer.o

test:
	make nanafy-buffer.exe
	./nanafy-buffer.exe

nanafy-buffer.exe: main.c compiled/test-nanafy-buffer.o compiled/test-copy-nanafy-buffer.o compiled/test-extend-nanafy-buffer.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-buffer.o compiled/test-copy-nanafy-buffer.o compiled/test-extend-nanafy-buffer.o -lnanafy -o nanafy-buffer.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-buffer.o: src/test-nanafy-buffer.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-nanafy-buffer.c -o compiled/test-nanafy-buffer.o

compiled/test-copy-nanafy-buffer.o: src/test-copy-nanafy-buffer.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-copy-nanafy-buffer.c -o compiled/test-copy-nanafy-buffer.o

compiled/test-extend-nanafy-buffer.o: src/test-extend-nanafy-buffer.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-extend-nanafy-buffer.c -o compiled/test-extend-nanafy-buffer.o
