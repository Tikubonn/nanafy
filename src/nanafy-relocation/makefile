
default:

clean:
	rm -f nanafy-relocation.h
	rm -f nanafy-relocation.lib
	rm -f compiled/init-nanafy-relative-relocation.o
	rm -f compiled/setup-image-relocation-with-nanafy-relocation.o
	rm -f compiled/sizeof-nanafy-relocation-product.o
	rm -f compiled/read-nanafy-relocation-product.o
	rm -f compiled/init-nanafy-relocation.o

nanafy-relocation.lib: compiled/init-nanafy-relative-relocation.o compiled/setup-image-relocation-with-nanafy-relocation.o compiled/sizeof-nanafy-relocation-product.o compiled/read-nanafy-relocation-product.o compiled/init-nanafy-relocation.o
	ar r nanafy-relocation.lib compiled/init-nanafy-relative-relocation.o compiled/setup-image-relocation-with-nanafy-relocation.o compiled/sizeof-nanafy-relocation-product.o compiled/read-nanafy-relocation-product.o compiled/init-nanafy-relocation.o

nanafy-relocation.h: src/init-nanafy-relative-relocation.h src/setup-image-relocation-with-nanafy-relocation.h src/sizeof-nanafy-relocation-product.h src/read-nanafy-relocation-product.h src/init-nanafy-relocation.h
	cat src/init-nanafy-relative-relocation.h src/setup-image-relocation-with-nanafy-relocation.h src/sizeof-nanafy-relocation-product.h src/read-nanafy-relocation-product.h src/init-nanafy-relocation.h > nanafy-relocation.h

compiled/init-nanafy-relative-relocation.o: src/init-nanafy-relative-relocation.c 
	gcc $(CFLAGS) -c src/init-nanafy-relative-relocation.c -o compiled/init-nanafy-relative-relocation.o

compiled/setup-image-relocation-with-nanafy-relocation.o: src/setup-image-relocation-with-nanafy-relocation.c 
	gcc $(CFLAGS) -c src/setup-image-relocation-with-nanafy-relocation.c -o compiled/setup-image-relocation-with-nanafy-relocation.o

compiled/sizeof-nanafy-relocation-product.o: src/sizeof-nanafy-relocation-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-relocation-product.c -o compiled/sizeof-nanafy-relocation-product.o

compiled/read-nanafy-relocation-product.o: src/read-nanafy-relocation-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-relocation-product.c -o compiled/read-nanafy-relocation-product.o

compiled/init-nanafy-relocation.o: src/init-nanafy-relocation.c 
	gcc $(CFLAGS) -c src/init-nanafy-relocation.c -o compiled/init-nanafy-relocation.o
