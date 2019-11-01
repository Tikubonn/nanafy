
default:

clean:
	rm -f nanafy-section.h
	rm -f nanafy-section.lib
	rm -f compiled/align-nanafy-section.o
	rm -f compiled/allocate-nanafy-section.o
	rm -f compiled/has-nanafy-section-margin.o
	rm -f compiled/nanafy-section-file-offset.o
	rm -f compiled/nanafy-section-file-size.o
	rm -f compiled/nanafy-section-memory-offset.o
	rm -f compiled/nanafy-section-memory-size.o
	rm -f compiled/put-nanafy-section.o
	rm -f compiled/read-nanafy-all-image-section-header-product.o
	rm -f compiled/read-nanafy-image-section-header-product.o
	rm -f compiled/read-nanafy-section-product.o
	rm -f compiled/set-nanafy-section.o
	rm -f compiled/setup-image-section-header-with-nanafy-section.o
	rm -f compiled/sizeof-nanafy-all-image-section-header-product.o
	rm -f compiled/sizeof-nanafy-image-section-header-product.o
	rm -f compiled/sizeof-nanafy-section-product.o
	rm -f compiled/tell-nanafy-section.o
	rm -f compiled/write-nanafy-section.o
	rm -f compiled/sizeof-nanafy-all-section-product.o
	rm -f compiled/read-nanafy-all-section-product.o
	rm -f compiled/countof-nanafy-image-section-header-product.o
	rm -f compiled/numberof-nanafy-image-section-header-product.o

nanafy-section.h: src/align-nanafy-section.h src/allocate-nanafy-section.h src/has-nanafy-section-margin.h src/nanafy-section-file-offset.h src/nanafy-section-file-size.h src/nanafy-section-memory-offset.h src/nanafy-section-memory-size.h src/put-nanafy-section.h src/read-nanafy-all-image-section-header-product.h src/read-nanafy-image-section-header-product.h src/read-nanafy-section-product.h src/set-nanafy-section.h src/setup-image-section-header-with-nanafy-section.h src/sizeof-nanafy-all-image-section-header-product.h src/sizeof-nanafy-image-section-header-product.h src/sizeof-nanafy-section-product.h src/tell-nanafy-section.h src/write-nanafy-section.h src/sizeof-nanafy-all-section-product.h src/read-nanafy-all-section-product.h src/countof-nanafy-image-section-header-product.h src/numberof-nanafy-image-section-header-product.h
	cat src/align-nanafy-section.h src/allocate-nanafy-section.h src/has-nanafy-section-margin.h src/nanafy-section-file-offset.h src/nanafy-section-file-size.h src/nanafy-section-memory-offset.h src/nanafy-section-memory-size.h src/put-nanafy-section.h src/read-nanafy-all-image-section-header-product.h src/read-nanafy-image-section-header-product.h src/read-nanafy-section-product.h src/set-nanafy-section.h src/setup-image-section-header-with-nanafy-section.h src/sizeof-nanafy-all-image-section-header-product.h src/sizeof-nanafy-image-section-header-product.h src/sizeof-nanafy-section-product.h src/tell-nanafy-section.h src/write-nanafy-section.h src/sizeof-nanafy-all-section-product.h src/read-nanafy-all-section-product.h src/countof-nanafy-image-section-header-product.h src/numberof-nanafy-image-section-header-product.h > nanafy-section.h

nanafy-section.lib: compiled/align-nanafy-section.o compiled/allocate-nanafy-section.o compiled/has-nanafy-section-margin.o compiled/nanafy-section-file-offset.o compiled/nanafy-section-file-size.o compiled/nanafy-section-memory-offset.o compiled/nanafy-section-memory-size.o compiled/put-nanafy-section.o compiled/read-nanafy-all-image-section-header-product.o compiled/read-nanafy-image-section-header-product.o compiled/read-nanafy-section-product.o compiled/set-nanafy-section.o compiled/setup-image-section-header-with-nanafy-section.o compiled/sizeof-nanafy-all-image-section-header-product.o compiled/sizeof-nanafy-image-section-header-product.o compiled/sizeof-nanafy-section-product.o compiled/tell-nanafy-section.o compiled/write-nanafy-section.o compiled/sizeof-nanafy-all-section-product.o compiled/read-nanafy-all-section-product.o compiled/countof-nanafy-image-section-header-product.o compiled/numberof-nanafy-image-section-header-product.o
	ar r nanafy-section.lib compiled/align-nanafy-section.o compiled/allocate-nanafy-section.o compiled/has-nanafy-section-margin.o compiled/nanafy-section-file-offset.o compiled/nanafy-section-file-size.o compiled/nanafy-section-memory-offset.o compiled/nanafy-section-memory-size.o compiled/put-nanafy-section.o compiled/read-nanafy-all-image-section-header-product.o compiled/read-nanafy-image-section-header-product.o compiled/read-nanafy-section-product.o compiled/set-nanafy-section.o compiled/setup-image-section-header-with-nanafy-section.o compiled/sizeof-nanafy-all-image-section-header-product.o compiled/sizeof-nanafy-image-section-header-product.o compiled/sizeof-nanafy-section-product.o compiled/tell-nanafy-section.o compiled/write-nanafy-section.o compiled/sizeof-nanafy-all-section-product.o compiled/read-nanafy-all-section-product.o compiled/countof-nanafy-image-section-header-product.o compiled/numberof-nanafy-image-section-header-product.o

compiled/align-nanafy-section.o: src/align-nanafy-section.c 
	gcc $(CFLAGS) -c src/align-nanafy-section.c -o compiled/align-nanafy-section.o

compiled/allocate-nanafy-section.o: src/allocate-nanafy-section.c 
	gcc $(CFLAGS) -c src/allocate-nanafy-section.c -o compiled/allocate-nanafy-section.o

compiled/has-nanafy-section-margin.o: src/has-nanafy-section-margin.c 
	gcc $(CFLAGS) -c src/has-nanafy-section-margin.c -o compiled/has-nanafy-section-margin.o

compiled/nanafy-section-file-offset.o: src/nanafy-section-file-offset.c 
	gcc $(CFLAGS) -c src/nanafy-section-file-offset.c -o compiled/nanafy-section-file-offset.o

compiled/nanafy-section-file-size.o: src/nanafy-section-file-size.c 
	gcc $(CFLAGS) -c src/nanafy-section-file-size.c -o compiled/nanafy-section-file-size.o

compiled/nanafy-section-memory-offset.o: src/nanafy-section-memory-offset.c 
	gcc $(CFLAGS) -c src/nanafy-section-memory-offset.c -o compiled/nanafy-section-memory-offset.o

compiled/nanafy-section-memory-size.o: src/nanafy-section-memory-size.c 
	gcc $(CFLAGS) -c src/nanafy-section-memory-size.c -o compiled/nanafy-section-memory-size.o

compiled/put-nanafy-section.o: src/put-nanafy-section.c 
	gcc $(CFLAGS) -c src/put-nanafy-section.c -o compiled/put-nanafy-section.o

compiled/read-nanafy-all-image-section-header-product.o: src/read-nanafy-all-image-section-header-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-all-image-section-header-product.c -o compiled/read-nanafy-all-image-section-header-product.o

compiled/read-nanafy-image-section-header-product.o: src/read-nanafy-image-section-header-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-image-section-header-product.c -o compiled/read-nanafy-image-section-header-product.o

compiled/read-nanafy-section-product.o: src/read-nanafy-section-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-section-product.c -o compiled/read-nanafy-section-product.o

compiled/set-nanafy-section.o: src/set-nanafy-section.c 
	gcc $(CFLAGS) -c src/set-nanafy-section.c -o compiled/set-nanafy-section.o

compiled/setup-image-section-header-with-nanafy-section.o: src/setup-image-section-header-with-nanafy-section.c 
	gcc $(CFLAGS) -c src/setup-image-section-header-with-nanafy-section.c -o compiled/setup-image-section-header-with-nanafy-section.o

compiled/sizeof-nanafy-all-image-section-header-product.o: src/sizeof-nanafy-all-image-section-header-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-all-image-section-header-product.c -o compiled/sizeof-nanafy-all-image-section-header-product.o

compiled/sizeof-nanafy-image-section-header-product.o: src/sizeof-nanafy-image-section-header-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-image-section-header-product.c -o compiled/sizeof-nanafy-image-section-header-product.o

compiled/sizeof-nanafy-section-product.o: src/sizeof-nanafy-section-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-section-product.c -o compiled/sizeof-nanafy-section-product.o

compiled/tell-nanafy-section.o: src/tell-nanafy-section.c 
	gcc $(CFLAGS) -c src/tell-nanafy-section.c -o compiled/tell-nanafy-section.o

compiled/write-nanafy-section.o: src/write-nanafy-section.c 
	gcc $(CFLAGS) -c src/write-nanafy-section.c -o compiled/write-nanafy-section.o

compiled/sizeof-nanafy-all-section-product.o: src/sizeof-nanafy-all-section-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-all-section-product.c -o compiled/sizeof-nanafy-all-section-product.o

compiled/read-nanafy-all-section-product.o: src/read-nanafy-all-section-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-all-section-product.c -o compiled/read-nanafy-all-section-product.o

compiled/countof-nanafy-image-section-header-product.o: src/countof-nanafy-image-section-header-product.c 
	gcc $(CFLAGS) -c src/countof-nanafy-image-section-header-product.c -o compiled/countof-nanafy-image-section-header-product.o

compiled/numberof-nanafy-image-section-header-product.o: src/numberof-nanafy-image-section-header-product.c 
	gcc $(CFLAGS) -c src/numberof-nanafy-image-section-header-product.c -o compiled/numberof-nanafy-image-section-header-product.o
