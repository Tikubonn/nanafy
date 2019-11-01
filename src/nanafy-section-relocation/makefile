
default:

clean:
	rm -f nanafy-section-relocation.h
	rm -f nanafy-section-relocation.lib
	rm -f compiled/add-nanafy-section-relative-relocation.o
	rm -f compiled/add-nanafy-section-relocation.o
	rm -f compiled/countof-nanafy-section-relocation-product.o
	rm -f compiled/read-nanafy-all-section-relocation-product.o
	rm -f compiled/read-nanafy-section-relocation-product.o
	rm -f compiled/sizeof-nanafy-all-section-relocation-product.o
	rm -f compiled/sizeof-nanafy-section-relocation-product.o
	rm -f compiled/offsetof-nanafy-section-relocation-product.o
	rm -f compiled/has-nanafy-section-relocation-margin.o

nanafy-section-relocation.h: src/add-nanafy-section-relative-relocation.h src/add-nanafy-section-relocation.h src/countof-nanafy-section-relocation-product.h src/read-nanafy-all-section-relocation-product.h src/read-nanafy-section-relocation-product.h src/sizeof-nanafy-all-section-relocation-product.h src/sizeof-nanafy-section-relocation-product.h src/offsetof-nanafy-section-relocation-product.h src/has-nanafy-section-relocation-margin.h
	cat src/add-nanafy-section-relative-relocation.h src/add-nanafy-section-relocation.h src/countof-nanafy-section-relocation-product.h src/read-nanafy-all-section-relocation-product.h src/read-nanafy-section-relocation-product.h src/sizeof-nanafy-all-section-relocation-product.h src/sizeof-nanafy-section-relocation-product.h src/offsetof-nanafy-section-relocation-product.h src/has-nanafy-section-relocation-margin.h > nanafy-section-relocation.h

nanafy-section-relocation.lib: compiled/add-nanafy-section-relative-relocation.o compiled/add-nanafy-section-relocation.o compiled/countof-nanafy-section-relocation-product.o compiled/read-nanafy-all-section-relocation-product.o compiled/read-nanafy-section-relocation-product.o compiled/sizeof-nanafy-all-section-relocation-product.o compiled/sizeof-nanafy-section-relocation-product.o compiled/offsetof-nanafy-section-relocation-product.o compiled/has-nanafy-section-relocation-margin.o
	ar r nanafy-section-relocation.lib compiled/add-nanafy-section-relative-relocation.o compiled/add-nanafy-section-relocation.o compiled/countof-nanafy-section-relocation-product.o compiled/read-nanafy-all-section-relocation-product.o compiled/read-nanafy-section-relocation-product.o compiled/sizeof-nanafy-all-section-relocation-product.o compiled/sizeof-nanafy-section-relocation-product.o compiled/offsetof-nanafy-section-relocation-product.o compiled/has-nanafy-section-relocation-margin.o

compiled/add-nanafy-section-relative-relocation.o: src/add-nanafy-section-relative-relocation.c 
	gcc $(CFLAGS) -c src/add-nanafy-section-relative-relocation.c -o compiled/add-nanafy-section-relative-relocation.o

compiled/add-nanafy-section-relocation.o: src/add-nanafy-section-relocation.c 
	gcc $(CFLAGS) -c src/add-nanafy-section-relocation.c -o compiled/add-nanafy-section-relocation.o

compiled/countof-nanafy-section-relocation-product.o: src/countof-nanafy-section-relocation-product.c 
	gcc $(CFLAGS) -c src/countof-nanafy-section-relocation-product.c -o compiled/countof-nanafy-section-relocation-product.o

compiled/read-nanafy-all-section-relocation-product.o: src/read-nanafy-all-section-relocation-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-all-section-relocation-product.c -o compiled/read-nanafy-all-section-relocation-product.o

compiled/read-nanafy-section-relocation-product.o: src/read-nanafy-section-relocation-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-section-relocation-product.c -o compiled/read-nanafy-section-relocation-product.o

compiled/sizeof-nanafy-all-section-relocation-product.o: src/sizeof-nanafy-all-section-relocation-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-all-section-relocation-product.c -o compiled/sizeof-nanafy-all-section-relocation-product.o

compiled/sizeof-nanafy-section-relocation-product.o: src/sizeof-nanafy-section-relocation-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-section-relocation-product.c -o compiled/sizeof-nanafy-section-relocation-product.o

compiled/offsetof-nanafy-section-relocation-product.o: src/offsetof-nanafy-section-relocation-product.c 
	gcc $(CFLAGS) -c src/offsetof-nanafy-section-relocation-product.c -o compiled/offsetof-nanafy-section-relocation-product.o

compiled/has-nanafy-section-relocation-margin.o: src/has-nanafy-section-relocation-margin.c 
	gcc $(CFLAGS) -c src/has-nanafy-section-relocation-margin.c -o compiled/has-nanafy-section-relocation-margin.o
