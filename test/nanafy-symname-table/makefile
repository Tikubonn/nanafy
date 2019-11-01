
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	nanafy.h
	rm -f compiled/test-nanafy-symname-table.o
	rm -f compiled/test-copy-nanafy-symname-table.o
	rm -f compiled/test-extend-nanafy-symname-table.o

test:
	make nanafy-symname-table.exe
	./nanafy-symname-table.exe

nanafy-symname-table.exe: main.c compiled/test-nanafy-symname-table.o compiled/test-copy-nanafy-symname-table.o compiled/test-extend-nanafy-symname-table.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-symname-table.o compiled/test-copy-nanafy-symname-table.o compiled/test-extend-nanafy-symname-table.o -lnanafy -o nanafy-symname-table.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-symname-table.o: src/test-nanafy-symname-table.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-nanafy-symname-table.c -o compiled/test-nanafy-symname-table.o

compiled/test-copy-nanafy-symname-table.o: src/test-copy-nanafy-symname-table.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-copy-nanafy-symname-table.c -o compiled/test-copy-nanafy-symname-table.o

compiled/test-extend-nanafy-symname-table.o: src/test-extend-nanafy-symname-table.c nanafy.h nanafy.dll 
	gcc $(CFLAGS) -c src/test-extend-nanafy-symname-table.c -o compiled/test-extend-nanafy-symname-table.o
