
default:

clean:
	rm -f nanafy-relocation-list.h
	rm -f nanafy-relocation-list.lib
	rm -f compiled/nanafy-relocation-list.o
	rm -f compiled/sizeof-nanafy-relocation-list-product.o
	rm -f compiled/read-nanafy-relocation-list-product.o

nanafy-relocation-list.lib: compiled/nanafy-relocation-list.o compiled/sizeof-nanafy-relocation-list-product.o compiled/read-nanafy-relocation-list-product.o
	ar r nanafy-relocation-list.lib compiled/nanafy-relocation-list.o compiled/sizeof-nanafy-relocation-list-product.o compiled/read-nanafy-relocation-list-product.o

nanafy-relocation-list.h: src/nanafy-relocation-list.h src/sizeof-nanafy-relocation-list-product.h src/read-nanafy-relocation-list-product.h
	cat src/nanafy-relocation-list.h src/sizeof-nanafy-relocation-list-product.h src/read-nanafy-relocation-list-product.h > nanafy-relocation-list.h

compiled/nanafy-relocation-list.o: src/nanafy-relocation-list.c 
	gcc $(CFLAGS) -c src/nanafy-relocation-list.c -o compiled/nanafy-relocation-list.o

compiled/sizeof-nanafy-relocation-list-product.o: src/sizeof-nanafy-relocation-list-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-relocation-list-product.c -o compiled/sizeof-nanafy-relocation-list-product.o

compiled/read-nanafy-relocation-list-product.o: src/read-nanafy-relocation-list-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-relocation-list-product.c -o compiled/read-nanafy-relocation-list-product.o
