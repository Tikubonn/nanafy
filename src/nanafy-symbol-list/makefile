
default:

clean:
	rm -f nanafy-symbol-list.h
	rm -f nanafy-symbol-list.lib
	rm -f compiled/nanafy-symbol-list.o
	rm -f compiled/sizeof-nanafy-symbol-list-product.o
	rm -f compiled/read-nanafy-symbol-list-product.o

nanafy-symbol-list.lib: compiled/nanafy-symbol-list.o compiled/sizeof-nanafy-symbol-list-product.o compiled/read-nanafy-symbol-list-product.o
	ar r nanafy-symbol-list.lib compiled/nanafy-symbol-list.o compiled/sizeof-nanafy-symbol-list-product.o compiled/read-nanafy-symbol-list-product.o

nanafy-symbol-list.h: src/nanafy-symbol-list.h src/sizeof-nanafy-symbol-list-product.h src/read-nanafy-symbol-list-product.h
	cat src/nanafy-symbol-list.h src/sizeof-nanafy-symbol-list-product.h src/read-nanafy-symbol-list-product.h > nanafy-symbol-list.h

compiled/nanafy-symbol-list.o: src/nanafy-symbol-list.c 
	gcc $(CFLAGS) -c src/nanafy-symbol-list.c -o compiled/nanafy-symbol-list.o

compiled/sizeof-nanafy-symbol-list-product.o: src/sizeof-nanafy-symbol-list-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-symbol-list-product.c -o compiled/sizeof-nanafy-symbol-list-product.o

compiled/read-nanafy-symbol-list-product.o: src/read-nanafy-symbol-list-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-symbol-list-product.c -o compiled/read-nanafy-symbol-list-product.o
