
default:

clean:
	rm -f nanafy-local-relocation.h
	rm -f nanafy-local-relocation.lib
	rm -f compiled/find-nanafy-local-relocation-list.o
	rm -f compiled/fix-nanafy-memory-with-local-relocation-list.o
	rm -f compiled/nanafy-local-relocation-list.o

nanafy-local-relocation-list.h: src/find-nanafy-local-relocation-list.h src/fix-nanafy-memory-with-local-relocation-list.h src/nanafy-local-relocation-list.h
	cat src/find-nanafy-local-relocation-list.h src/fix-nanafy-memory-with-local-relocation-list.h src/nanafy-local-relocation-list.h > nanafy-local-relocation-list.h

nanafy-local-relocation-list.lib: compiled/find-nanafy-local-relocation-list.o compiled/fix-nanafy-memory-with-local-relocation-list.o compiled/nanafy-local-relocation-list.o
	ar r nanafy-local-relocation-list.lib compiled/find-nanafy-local-relocation-list.o compiled/fix-nanafy-memory-with-local-relocation-list.o compiled/nanafy-local-relocation-list.o

compiled/find-nanafy-local-relocation-list.o: src/find-nanafy-local-relocation-list.c 
	gcc $(CFLAGS) -c src/find-nanafy-local-relocation-list.c -o compiled/find-nanafy-local-relocation-list.o

compiled/fix-nanafy-memory-with-local-relocation-list.o: src/fix-nanafy-memory-with-local-relocation-list.c 
	gcc $(CFLAGS) -c src/fix-nanafy-memory-with-local-relocation-list.c -o compiled/fix-nanafy-memory-with-local-relocation-list.o

compiled/nanafy-local-relocation-list.o: src/nanafy-local-relocation-list.c 
	gcc $(CFLAGS) -c src/nanafy-local-relocation-list.c -o compiled/nanafy-local-relocation-list.o
