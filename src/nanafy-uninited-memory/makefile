
default:

clean:
	rm -f nanafy-uninited-memory.h
	rm -f nanafy-uninited-memory.lib
	rm -f compiled/init-nanafy-uninited-memory.o
	rm -f compiled/allocate-nanafy-uninited-memory.o
	rm -f compiled/align-nanafy-uninited-memory.o
	rm -f compiled/tell-nanafy-uninited-memory.o
	rm -f compiled/sizeof-nanafy-uninited-memory-product.o
	rm -f compiled/read-nanafy-uninited-memory-product.o

nanafy-uninited-memory.h: src/init-nanafy-uninited-memory.h src/allocate-nanafy-uninited-memory.h src/align-nanafy-uninited-memory.h src/tell-nanafy-uninited-memory.h src/sizeof-nanafy-uninited-memory-product.h src/read-nanafy-uninited-memory-product.h
	cat src/init-nanafy-uninited-memory.h src/allocate-nanafy-uninited-memory.h src/align-nanafy-uninited-memory.h src/tell-nanafy-uninited-memory.h src/sizeof-nanafy-uninited-memory-product.h src/read-nanafy-uninited-memory-product.h > nanafy-uninited-memory.h

nanafy-uninited-memory.lib: compiled/init-nanafy-uninited-memory.o compiled/allocate-nanafy-uninited-memory.o compiled/align-nanafy-uninited-memory.o compiled/tell-nanafy-uninited-memory.o compiled/sizeof-nanafy-uninited-memory-product.o compiled/read-nanafy-uninited-memory-product.o
	ar r nanafy-uninited-memory.lib compiled/init-nanafy-uninited-memory.o compiled/allocate-nanafy-uninited-memory.o compiled/align-nanafy-uninited-memory.o compiled/tell-nanafy-uninited-memory.o compiled/sizeof-nanafy-uninited-memory-product.o compiled/read-nanafy-uninited-memory-product.o

compiled/init-nanafy-uninited-memory.o: src/init-nanafy-uninited-memory.c 
	gcc $(CFLAGS) -c src/init-nanafy-uninited-memory.c -o compiled/init-nanafy-uninited-memory.o

compiled/allocate-nanafy-uninited-memory.o: src/allocate-nanafy-uninited-memory.c 
	gcc $(CFLAGS) -c src/allocate-nanafy-uninited-memory.c -o compiled/allocate-nanafy-uninited-memory.o

compiled/align-nanafy-uninited-memory.o: src/align-nanafy-uninited-memory.c 
	gcc $(CFLAGS) -c src/align-nanafy-uninited-memory.c -o compiled/align-nanafy-uninited-memory.o

compiled/tell-nanafy-uninited-memory.o: src/tell-nanafy-uninited-memory.c 
	gcc $(CFLAGS) -c src/tell-nanafy-uninited-memory.c -o compiled/tell-nanafy-uninited-memory.o

compiled/sizeof-nanafy-uninited-memory-product.o: src/sizeof-nanafy-uninited-memory-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-uninited-memory-product.c -o compiled/sizeof-nanafy-uninited-memory-product.o

compiled/read-nanafy-uninited-memory-product.o: src/read-nanafy-uninited-memory-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-uninited-memory-product.c -o compiled/read-nanafy-uninited-memory-product.o
