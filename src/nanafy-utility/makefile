
default:

clean:
	rm -f nanafy-utility.h
	rm -f nanafy-utility.lib
	rm -f compiled/alignment-padding-nanafy.o
	rm -f compiled/strlen-nanafy.o
	rm -f compiled/strcmp-nanafy.o
	rm -f compiled/big-endian-nanafy.o
	rm -f compiled/little-endian-nanafy.o
	rm -f compiled/endian-nanafy.o

nanafy-utility.h: src/alignment-padding-nanafy.h src/strlen-nanafy.h src/strcmp-nanafy.h src/big-endian-nanafy.h src/little-endian-nanafy.h src/endian-nanafy.h
	cat src/alignment-padding-nanafy.h src/strlen-nanafy.h src/strcmp-nanafy.h src/big-endian-nanafy.h src/little-endian-nanafy.h src/endian-nanafy.h > nanafy-utility.h

nanafy-utility.lib: compiled/alignment-padding-nanafy.o compiled/strlen-nanafy.o compiled/strcmp-nanafy.o compiled/big-endian-nanafy.o compiled/little-endian-nanafy.o compiled/endian-nanafy.o
	ar r nanafy-utility.lib compiled/alignment-padding-nanafy.o compiled/strlen-nanafy.o compiled/strcmp-nanafy.o compiled/big-endian-nanafy.o compiled/little-endian-nanafy.o compiled/endian-nanafy.o

compiled/alignment-padding-nanafy.o: src/alignment-padding-nanafy.c
	gcc $(CFLAGS) -c src/alignment-padding-nanafy.c -o compiled/alignment-padding-nanafy.o

compiled/strlen-nanafy.o: src/strlen-nanafy.c
	gcc $(CFLAGS) -c src/strlen-nanafy.c -o compiled/strlen-nanafy.o

compiled/strcmp-nanafy.o: src/strcmp-nanafy.c
	gcc $(CFLAGS) -c src/strcmp-nanafy.c -o compiled/strcmp-nanafy.o

compiled/big-endian-nanafy.o: src/big-endian-nanafy.c
	gcc $(CFLAGS) -c src/big-endian-nanafy.c -o compiled/big-endian-nanafy.o

compiled/little-endian-nanafy.o: src/little-endian-nanafy.c
	gcc $(CFLAGS) -c src/little-endian-nanafy.c -o compiled/little-endian-nanafy.o

compiled/endian-nanafy.o: src/endian-nanafy.c
	gcc $(CFLAGS) -c src/endian-nanafy.c -o compiled/endian-nanafy.o
