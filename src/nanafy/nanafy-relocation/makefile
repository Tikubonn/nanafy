
clean:
	rm -f nanafy-relocation.h
	rm -f nanafy-relocation.lib
	rm -f compiled/put-nanafy-external-offset.o
	rm -f compiled/put-nanafy-external-offset-manually.o
	rm -f compiled/put-nanafy-external-relative-offset.o
	rm -f compiled/put-nanafy-external-relative-offset-manually.o

nanafy-relocation.lib: compiled/put-nanafy-external-offset.o compiled/put-nanafy-external-offset-manually.o compiled/put-nanafy-external-relative-offset.o compiled/put-nanafy-external-relative-offset-manually.o
	ar r nanafy-relocation.lib compiled/put-nanafy-external-offset.o compiled/put-nanafy-external-offset-manually.o compiled/put-nanafy-external-relative-offset.o compiled/put-nanafy-external-relative-offset-manually.o

nanafy-relocation.h: src/put-nanafy-external-offset.h src/put-nanafy-external-offset-manually.h src/put-nanafy-external-relative-offset.h src/put-nanafy-external-relative-offset-manually.h
	cat src/put-nanafy-external-offset.h src/put-nanafy-external-offset-manually.h src/put-nanafy-external-relative-offset.h src/put-nanafy-external-relative-offset-manually.h > nanafy-relocation.h

compiled/put-nanafy-external-offset.o: src/put-nanafy-external-offset.c 
	gcc $(CFLAGS) -c src/put-nanafy-external-offset.c -o compiled/put-nanafy-external-offset.o

compiled/put-nanafy-external-offset-manually.o: src/put-nanafy-external-offset-manually.c 
	gcc $(CFLAGS) -c src/put-nanafy-external-offset-manually.c -o compiled/put-nanafy-external-offset-manually.o

compiled/put-nanafy-external-relative-offset.o: src/put-nanafy-external-relative-offset.c 
	gcc $(CFLAGS) -c src/put-nanafy-external-relative-offset.c -o compiled/put-nanafy-external-relative-offset.o

compiled/put-nanafy-external-relative-offset-manually.o: src/put-nanafy-external-relative-offset-manually.c 
	gcc $(CFLAGS) -c src/put-nanafy-external-relative-offset-manually.c -o compiled/put-nanafy-external-relative-offset-manually.o
