
default:

clean:
	rm -f nanafy-symbol.h
	rm -f nanafy-symbol.lib
	rm -f compiled/init-nanafy-symbol.o
	rm -f compiled/init-nanafy-external-symbol.o
	rm -f compiled/nanafy-symbol-symname-offset.o
	rm -f compiled/setup-image-symbol-with-nanafy-symbol.o
	rm -f compiled/sizeof-nanafy-symbol-product.o
	rm -f compiled/read-nanafy-symbol-product.o
	rm -f compiled/init-nanafy-private-symbol.o

nanafy-symbol.h: src/init-nanafy-symbol.h src/init-nanafy-external-symbol.h src/nanafy-symbol-symname-offset.h src/setup-image-symbol-with-nanafy-symbol.h src/sizeof-nanafy-symbol-product.h src/read-nanafy-symbol-product.h src/init-nanafy-private-symbol.h
	cat src/init-nanafy-symbol.h src/init-nanafy-external-symbol.h src/nanafy-symbol-symname-offset.h src/setup-image-symbol-with-nanafy-symbol.h src/sizeof-nanafy-symbol-product.h src/read-nanafy-symbol-product.h src/init-nanafy-private-symbol.h > nanafy-symbol.h

nanafy-symbol.lib: compiled/init-nanafy-symbol.o compiled/init-nanafy-external-symbol.o compiled/nanafy-symbol-symname-offset.o compiled/setup-image-symbol-with-nanafy-symbol.o compiled/sizeof-nanafy-symbol-product.o compiled/read-nanafy-symbol-product.o compiled/init-nanafy-private-symbol.o
	ar r nanafy-symbol.lib compiled/init-nanafy-symbol.o compiled/init-nanafy-external-symbol.o compiled/nanafy-symbol-symname-offset.o compiled/setup-image-symbol-with-nanafy-symbol.o compiled/sizeof-nanafy-symbol-product.o compiled/read-nanafy-symbol-product.o compiled/init-nanafy-private-symbol.o

compiled/init-nanafy-symbol.o: src/init-nanafy-symbol.c 
	gcc $(CFLAGS) -c src/init-nanafy-symbol.c -o compiled/init-nanafy-symbol.o

compiled/init-nanafy-external-symbol.o: src/init-nanafy-external-symbol.c 
	gcc $(CFLAGS) -c src/init-nanafy-external-symbol.c -o compiled/init-nanafy-external-symbol.o

compiled/nanafy-symbol-symname-offset.o: src/nanafy-symbol-symname-offset.c 
	gcc $(CFLAGS) -c src/nanafy-symbol-symname-offset.c -o compiled/nanafy-symbol-symname-offset.o

compiled/setup-image-symbol-with-nanafy-symbol.o: src/setup-image-symbol-with-nanafy-symbol.c 
	gcc $(CFLAGS) -c src/setup-image-symbol-with-nanafy-symbol.c -o compiled/setup-image-symbol-with-nanafy-symbol.o

compiled/sizeof-nanafy-symbol-product.o: src/sizeof-nanafy-symbol-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-symbol-product.c -o compiled/sizeof-nanafy-symbol-product.o

compiled/read-nanafy-symbol-product.o: src/read-nanafy-symbol-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-symbol-product.c -o compiled/read-nanafy-symbol-product.o

compiled/init-nanafy-private-symbol.o: src/init-nanafy-private-symbol.c 
	gcc $(CFLAGS) -c src/init-nanafy-private-symbol.c -o compiled/init-nanafy-private-symbol.o
