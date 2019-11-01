
default:

clean:
	rm -f nanafy-memory.h
	rm -f nanafy-memory.lib
	rm -f compiled/put-nanafy-manually.o
	rm -f compiled/put-nanafy.o
	rm -f compiled/write-nanafy-manually.o
	rm -f compiled/write-nanafy.o
	rm -f compiled/align-nanafy-manually.o
	rm -f compiled/align-nanafy.o
	rm -f compiled/allocate-nanafy-manually.o
	rm -f compiled/allocate-nanafy.o
	rm -f compiled/tell-nanafy.o

nanafy-memory.h: src/put-nanafy-manually.h src/put-nanafy.h src/write-nanafy-manually.h src/write-nanafy.h src/align-nanafy-manually.h src/align-nanafy.h src/allocate-nanafy-manually.h src/allocate-nanafy.h src/tell-nanafy.h
	cat src/put-nanafy-manually.h src/put-nanafy.h src/write-nanafy-manually.h src/write-nanafy.h src/align-nanafy-manually.h src/align-nanafy.h src/allocate-nanafy-manually.h src/allocate-nanafy.h src/tell-nanafy.h > nanafy-memory.h

nanafy-memory.lib: compiled/put-nanafy-manually.o compiled/put-nanafy.o compiled/write-nanafy-manually.o compiled/write-nanafy.o compiled/align-nanafy-manually.o compiled/align-nanafy.o compiled/allocate-nanafy-manually.o compiled/allocate-nanafy.o compiled/tell-nanafy.o
	ar r nanafy-memory.lib compiled/put-nanafy-manually.o compiled/put-nanafy.o compiled/write-nanafy-manually.o compiled/write-nanafy.o compiled/align-nanafy-manually.o compiled/align-nanafy.o compiled/allocate-nanafy-manually.o compiled/allocate-nanafy.o compiled/tell-nanafy.o

compiled/put-nanafy-manually.o: src/put-nanafy-manually.c 
	gcc $(CFLAGS) -c src/put-nanafy-manually.c -o compiled/put-nanafy-manually.o

compiled/put-nanafy.o: src/put-nanafy.c 
	gcc $(CFLAGS) -c src/put-nanafy.c -o compiled/put-nanafy.o

compiled/write-nanafy-manually.o: src/write-nanafy-manually.c 
	gcc $(CFLAGS) -c src/write-nanafy-manually.c -o compiled/write-nanafy-manually.o

compiled/write-nanafy.o: src/write-nanafy.c 
	gcc $(CFLAGS) -c src/write-nanafy.c -o compiled/write-nanafy.o

compiled/align-nanafy-manually.o: src/align-nanafy-manually.c 
	gcc $(CFLAGS) -c src/align-nanafy-manually.c -o compiled/align-nanafy-manually.o

compiled/align-nanafy.o: src/align-nanafy.c 
	gcc $(CFLAGS) -c src/align-nanafy.c -o compiled/align-nanafy.o

compiled/allocate-nanafy-manually.o: src/allocate-nanafy-manually.c 
	gcc $(CFLAGS) -c src/allocate-nanafy-manually.c -o compiled/allocate-nanafy-manually.o

compiled/allocate-nanafy.o: src/allocate-nanafy.c 
	gcc $(CFLAGS) -c src/allocate-nanafy.c -o compiled/allocate-nanafy.o

compiled/tell-nanafy.o: src/tell-nanafy.c
	gcc $(CFLAGS) -c src/tell-nanafy.c -o compiled/tell-nanafy.o
