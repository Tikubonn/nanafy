
default:

clean:
	rm -f nanafy.h
	rm -f nanafy.lib
	rm -f compiled/setup-image-file-header-with-nanafy.o
	rm -f compiled/sizeof-nanafy-image-file-header-product.o
	rm -f compiled/read-nanafy-image-file-header-product.o
	rm -f compiled/init-nanafy.o
	rm -f compiled/make-nanafy.o
	rm -f compiled/free-nanafy.o
	rm -f compiled/sizeof-nanafy-product.o
	rm -f compiled/read-nanafy-product.o
	rm -f compiled/init-empty-nanafy.o
	rm -f compiled/make-empty-nanafy.o

nanafy.h: src/setup-image-file-header-with-nanafy.h src/sizeof-nanafy-image-file-header-product.h src/read-nanafy-image-file-header-product.h src/init-nanafy.h src/make-nanafy.h src/free-nanafy.h src/sizeof-nanafy-product.h src/read-nanafy-product.h src/init-empty-nanafy.h src/make-empty-nanafy.h
	cat src/setup-image-file-header-with-nanafy.h src/sizeof-nanafy-image-file-header-product.h src/read-nanafy-image-file-header-product.h src/init-nanafy.h src/make-nanafy.h src/free-nanafy.h src/sizeof-nanafy-product.h src/read-nanafy-product.h src/init-empty-nanafy.h src/make-empty-nanafy.h > nanafy.h

nanafy.lib: compiled/setup-image-file-header-with-nanafy.o compiled/sizeof-nanafy-image-file-header-product.o compiled/read-nanafy-image-file-header-product.o compiled/init-nanafy.o compiled/make-nanafy.o compiled/free-nanafy.o compiled/sizeof-nanafy-product.o compiled/read-nanafy-product.o compiled/init-empty-nanafy.o compiled/make-empty-nanafy.o
	ar r nanafy.lib compiled/setup-image-file-header-with-nanafy.o compiled/sizeof-nanafy-image-file-header-product.o compiled/read-nanafy-image-file-header-product.o compiled/init-nanafy.o compiled/make-nanafy.o compiled/free-nanafy.o compiled/sizeof-nanafy-product.o compiled/read-nanafy-product.o compiled/init-empty-nanafy.o compiled/make-empty-nanafy.o

compiled/setup-image-file-header-with-nanafy.o: src/setup-image-file-header-with-nanafy.c 
	gcc $(CFLAGS) -c src/setup-image-file-header-with-nanafy.c -o compiled/setup-image-file-header-with-nanafy.o

compiled/sizeof-nanafy-image-file-header-product.o: src/sizeof-nanafy-image-file-header-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-image-file-header-product.c -o compiled/sizeof-nanafy-image-file-header-product.o

compiled/read-nanafy-image-file-header-product.o: src/read-nanafy-image-file-header-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-image-file-header-product.c -o compiled/read-nanafy-image-file-header-product.o

compiled/init-nanafy.o: src/init-nanafy.c 
	gcc $(CFLAGS) -c src/init-nanafy.c -o compiled/init-nanafy.o

compiled/make-nanafy.o: src/make-nanafy.c 
	gcc $(CFLAGS) -c src/make-nanafy.c -o compiled/make-nanafy.o

compiled/free-nanafy.o: src/free-nanafy.c 
	gcc $(CFLAGS) -c src/free-nanafy.c -o compiled/free-nanafy.o

compiled/sizeof-nanafy-product.o: src/sizeof-nanafy-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-product.c -o compiled/sizeof-nanafy-product.o

compiled/read-nanafy-product.o: src/read-nanafy-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-product.c -o compiled/read-nanafy-product.o

compiled/init-empty-nanafy.o: src/init-empty-nanafy.c 
	gcc $(CFLAGS) -c src/init-empty-nanafy.c -o compiled/init-empty-nanafy.o

compiled/make-empty-nanafy.o: src/make-empty-nanafy.c 
	gcc $(CFLAGS) -c src/make-empty-nanafy.c -o compiled/make-empty-nanafy.o
