
default:

clean:
	rm -f nanafy-local-relocation.h
	rm -f nanafy-local-relocation.lib
	rm -f compiled/put-nanafy-offset-manually.o
	rm -f compiled/put-nanafy-offset.o
	rm -f compiled/set-nanafy-offset-manually.o
	rm -f compiled/set-nanafy-offset.o

nanafy-local-relocation.lib: compiled/put-nanafy-offset-manually.o compiled/put-nanafy-offset.o compiled/set-nanafy-offset-manually.o compiled/set-nanafy-offset.o
	ar r nanafy-local-relocation.lib compiled/put-nanafy-offset-manually.o compiled/put-nanafy-offset.o compiled/set-nanafy-offset-manually.o compiled/set-nanafy-offset.o

nanafy-local-relocation.h: src/put-nanafy-offset-manually.h src/put-nanafy-offset.h src/set-nanafy-offset-manually.h src/set-nanafy-offset.h
	cat src/put-nanafy-offset-manually.h src/put-nanafy-offset.h src/set-nanafy-offset-manually.h src/set-nanafy-offset.h> nanafy-local-relocation.h

compiled/put-nanafy-offset-manually.o: src/put-nanafy-offset-manually.c 
	gcc $(CFLAGS) -c src/put-nanafy-offset-manually.c -o compiled/put-nanafy-offset-manually.o

compiled/put-nanafy-offset.o: src/put-nanafy-offset.c 
	gcc $(CFLAGS) -c src/put-nanafy-offset.c -o compiled/put-nanafy-offset.o

compiled/set-nanafy-offset-manually.o: src/set-nanafy-offset-manually.c 
	gcc $(CFLAGS) -c src/set-nanafy-offset-manually.c -o compiled/set-nanafy-offset-manually.o

compiled/set-nanafy-offset.o: src/set-nanafy-offset.c 
	gcc $(CFLAGS) -c src/set-nanafy-offset.c -o compiled/set-nanafy-offset.o
