
default:

clean:
	rm -f nanafy-memory.h
	rm -f nanafy-memory.lib
	rm -f compiled/init-nanafy-memory.o
	rm -f compiled/put-nanafy-memory.o
	rm -f compiled/write-nanafy-memory.o
	rm -f compiled/tell-nanafy-memory.o
	rm -f compiled/has-nanafy-memory-margin.o
	rm -f compiled/extend-nanafy-memory.o
	rm -f compiled/free-nanafy-memory.o
	rm -f compiled/sizeof-nanafy-memory-product.o
	rm -f compiled/read-nanafy-memory-product.o
	rm -f compiled/align-nanafy-memory.o
	rm -f compiled/set-nanafy-memory.o
	rm -f compiled/rewrite-nanafy-memory.o
	rm -f compiled/copy-nanafy-memory.o

nanafy-memory.h: src/init-nanafy-memory.h src/put-nanafy-memory.h src/write-nanafy-memory.h src/tell-nanafy-memory.h src/has-nanafy-memory-margin.h src/extend-nanafy-memory.h src/free-nanafy-memory.h src/sizeof-nanafy-memory-product.h src/read-nanafy-memory-product.h src/align-nanafy-memory.h src/set-nanafy-memory.h src/rewrite-nanafy-memory.h src/copy-nanafy-memory.h
	cat src/init-nanafy-memory.h src/put-nanafy-memory.h src/write-nanafy-memory.h src/tell-nanafy-memory.h src/has-nanafy-memory-margin.h src/extend-nanafy-memory.h src/free-nanafy-memory.h src/sizeof-nanafy-memory-product.h src/read-nanafy-memory-product.h src/align-nanafy-memory.h src/set-nanafy-memory.h src/rewrite-nanafy-memory.h src/copy-nanafy-memory.h > nanafy-memory.h

nanafy-memory.lib: compiled/init-nanafy-memory.o compiled/put-nanafy-memory.o compiled/write-nanafy-memory.o compiled/tell-nanafy-memory.o compiled/has-nanafy-memory-margin.o compiled/extend-nanafy-memory.o compiled/free-nanafy-memory.o compiled/sizeof-nanafy-memory-product.o compiled/read-nanafy-memory-product.o compiled/align-nanafy-memory.o compiled/set-nanafy-memory.o compiled/rewrite-nanafy-memory.o compiled/copy-nanafy-memory.o
	ar r nanafy-memory.lib compiled/init-nanafy-memory.o compiled/put-nanafy-memory.o compiled/write-nanafy-memory.o compiled/tell-nanafy-memory.o compiled/has-nanafy-memory-margin.o compiled/extend-nanafy-memory.o compiled/free-nanafy-memory.o compiled/sizeof-nanafy-memory-product.o compiled/read-nanafy-memory-product.o compiled/align-nanafy-memory.o compiled/set-nanafy-memory.o compiled/rewrite-nanafy-memory.o compiled/copy-nanafy-memory.o

compiled/init-nanafy-memory.o: src/init-nanafy-memory.c 
	gcc $(CFLAGS) -c src/init-nanafy-memory.c -o compiled/init-nanafy-memory.o

compiled/put-nanafy-memory.o: src/put-nanafy-memory.c 
	gcc $(CFLAGS) -c src/put-nanafy-memory.c -o compiled/put-nanafy-memory.o

compiled/write-nanafy-memory.o: src/write-nanafy-memory.c 
	gcc $(CFLAGS) -c src/write-nanafy-memory.c -o compiled/write-nanafy-memory.o

compiled/tell-nanafy-memory.o: src/tell-nanafy-memory.c 
	gcc $(CFLAGS) -c src/tell-nanafy-memory.c -o compiled/tell-nanafy-memory.o

compiled/has-nanafy-memory-margin.o: src/has-nanafy-memory-margin.c 
	gcc $(CFLAGS) -c src/has-nanafy-memory-margin.c -o compiled/has-nanafy-memory-margin.o

compiled/extend-nanafy-memory.o: src/extend-nanafy-memory.c 
	gcc $(CFLAGS) -c src/extend-nanafy-memory.c -o compiled/extend-nanafy-memory.o

compiled/free-nanafy-memory.o: src/free-nanafy-memory.c 
	gcc $(CFLAGS) -c src/free-nanafy-memory.c -o compiled/free-nanafy-memory.o

compiled/sizeof-nanafy-memory-product.o: src/sizeof-nanafy-memory-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-memory-product.c -o compiled/sizeof-nanafy-memory-product.o

compiled/read-nanafy-memory-product.o: src/read-nanafy-memory-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-memory-product.c -o compiled/read-nanafy-memory-product.o

compiled/align-nanafy-memory.o: src/align-nanafy-memory.c 
	gcc $(CFLAGS) -c src/align-nanafy-memory.c -o compiled/align-nanafy-memory.o

compiled/set-nanafy-memory.o: src/set-nanafy-memory.c 
	gcc $(CFLAGS) -c src/set-nanafy-memory.c -o compiled/set-nanafy-memory.o

compiled/rewrite-nanafy-memory.o: src/rewrite-nanafy-memory.c 
	gcc $(CFLAGS) -c src/rewrite-nanafy-memory.c -o compiled/rewrite-nanafy-memory.o

compiled/copy-nanafy-memory.o: src/copy-nanafy-memory.c 
	gcc $(CFLAGS) -c src/copy-nanafy-memory.c -o compiled/copy-nanafy-memory.o
