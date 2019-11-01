
default:

clean:
	rm -f nanafy-symname-table.h
	rm -f nanafy-symname-table.lib
	rm -f compiled/add-nanafy-symname-table.o
	rm -f compiled/copy-nanafy-symname-table.o
	rm -f compiled/extend-nanafy-symname-table.o
	rm -f compiled/find-nanafy-symname-table.o
	rm -f compiled/free-nanafy-symname-table.o
	rm -f compiled/init-nanafy-symname-table.o
	rm -f compiled/read-nanafy-symname-table-product.o
	rm -f compiled/sizeof-nanafy-symname-table-product.o
	rm -f compiled/nanafy-symname-table-default-hash-func.o

nanafy-symname-table.h: src/add-nanafy-symname-table.h src/copy-nanafy-symname-table.h src/extend-nanafy-symname-table.h src/find-nanafy-symname-table.h src/free-nanafy-symname-table.h src/init-nanafy-symname-table.h src/read-nanafy-symname-table-product.h src/sizeof-nanafy-symname-table-product.h src/nanafy-symname-table-default-hash-func.h
	cat src/add-nanafy-symname-table.h src/copy-nanafy-symname-table.h src/extend-nanafy-symname-table.h src/find-nanafy-symname-table.h src/free-nanafy-symname-table.h src/init-nanafy-symname-table.h src/read-nanafy-symname-table-product.h src/sizeof-nanafy-symname-table-product.h src/nanafy-symname-table-default-hash-func.h > nanafy-symname-table.h

nanafy-symname-table.lib: compiled/add-nanafy-symname-table.o compiled/copy-nanafy-symname-table.o compiled/extend-nanafy-symname-table.o compiled/find-nanafy-symname-table.o compiled/free-nanafy-symname-table.o compiled/init-nanafy-symname-table.o compiled/read-nanafy-symname-table-product.o compiled/sizeof-nanafy-symname-table-product.o compiled/nanafy-symname-table-default-hash-func.o
	ar r nanafy-symname-table.lib compiled/add-nanafy-symname-table.o compiled/copy-nanafy-symname-table.o compiled/extend-nanafy-symname-table.o compiled/find-nanafy-symname-table.o compiled/free-nanafy-symname-table.o compiled/init-nanafy-symname-table.o compiled/read-nanafy-symname-table-product.o compiled/sizeof-nanafy-symname-table-product.o compiled/nanafy-symname-table-default-hash-func.o

compiled/add-nanafy-symname-table.o: src/add-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/add-nanafy-symname-table.c -o compiled/add-nanafy-symname-table.o

compiled/copy-nanafy-symname-table.o: src/copy-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/copy-nanafy-symname-table.c -o compiled/copy-nanafy-symname-table.o

compiled/extend-nanafy-symname-table.o: src/extend-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/extend-nanafy-symname-table.c -o compiled/extend-nanafy-symname-table.o

compiled/find-nanafy-symname-table.o: src/find-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/find-nanafy-symname-table.c -o compiled/find-nanafy-symname-table.o

compiled/free-nanafy-symname-table.o: src/free-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/free-nanafy-symname-table.c -o compiled/free-nanafy-symname-table.o

compiled/init-nanafy-symname-table.o: src/init-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/init-nanafy-symname-table.c -o compiled/init-nanafy-symname-table.o

compiled/read-nanafy-symname-table-product.o: src/read-nanafy-symname-table-product.c 
	gcc $(CFLAGS) -c src/read-nanafy-symname-table-product.c -o compiled/read-nanafy-symname-table-product.o

compiled/sizeof-nanafy-symname-table-product.o: src/sizeof-nanafy-symname-table-product.c 
	gcc $(CFLAGS) -c src/sizeof-nanafy-symname-table-product.c -o compiled/sizeof-nanafy-symname-table-product.o

compiled/nanafy-symname-table-default-hash-func.o: src/nanafy-symname-table-default-hash-func.c 
	gcc $(CFLAGS) -c src/nanafy-symname-table-default-hash-func.c -o compiled/nanafy-symname-table-default-hash-func.o
