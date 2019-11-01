
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	nanafy.h
	rm -f compiled/nanafy-int-list.o
	rm -f compiled/test-nanafy-list.o
	rm -f compiled/test-copy-nanafy-list.o
	rm -f compiled/test-extend-nanafy-list.o

test:
	make nanafy-list.exe
	./nanafy-list.exe

nanafy-list.exe: main.c compiled/nanafy-int-list.o compiled/test-nanafy-list.o compiled/test-copy-nanafy-list.o compiled/test-extend-nanafy-list.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/nanafy-int-list.o compiled/test-nanafy-list.o compiled/test-copy-nanafy-list.o compiled/test-extend-nanafy-list.o -lnanafy -o nanafy-list.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/nanafy-int-list.o: src/nanafy-int-list.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/nanafy-int-list.c -o compiled/nanafy-int-list.o

compiled/test-nanafy-list.o: src/test-nanafy-list.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-nanafy-list.c -o compiled/test-nanafy-list.o

compiled/test-copy-nanafy-list.o: src/test-copy-nanafy-list.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-copy-nanafy-list.c -o compiled/test-copy-nanafy-list.o

compiled/test-extend-nanafy-list.o: src/test-extend-nanafy-list.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-extend-nanafy-list.c -o compiled/test-extend-nanafy-list.o
