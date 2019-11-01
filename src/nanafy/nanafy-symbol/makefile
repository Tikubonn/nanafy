
default:

clean:
	rm -f nanafy-symbol.h
	rm -f nanafy-symbol.lib
	rm -f compiled/register-nanafy-external-symbol-manually.o
	rm -f compiled/register-nanafy-external-symbol.o
	rm -f compiled/register-nanafy-symbol-manually.o
	rm -f compiled/register-nanafy-symbol.o
	rm -f compiled/register-nanafy-private-symbol-manually.o
	rm -f compiled/register-nanafy-private-symbol.o

nanafy-symbol.h: src/register-nanafy-external-symbol-manually.h src/register-nanafy-external-symbol.h src/register-nanafy-symbol-manually.h src/register-nanafy-symbol.h src/register-nanafy-private-symbol-manually.h src/register-nanafy-private-symbol.h
	cat src/register-nanafy-external-symbol-manually.h src/register-nanafy-external-symbol.h src/register-nanafy-symbol-manually.h src/register-nanafy-symbol.h src/register-nanafy-private-symbol-manually.h src/register-nanafy-private-symbol.h > nanafy-symbol.h

nanafy-symbol.lib: compiled/register-nanafy-external-symbol-manually.o compiled/register-nanafy-external-symbol.o compiled/register-nanafy-symbol-manually.o compiled/register-nanafy-symbol.o compiled/register-nanafy-private-symbol-manually.o compiled/register-nanafy-private-symbol.o
	ar r nanafy-symbol.lib compiled/register-nanafy-external-symbol-manually.o compiled/register-nanafy-external-symbol.o compiled/register-nanafy-symbol-manually.o compiled/register-nanafy-symbol.o compiled/register-nanafy-private-symbol-manually.o compiled/register-nanafy-private-symbol.o

compiled/register-nanafy-external-symbol-manually.o: src/register-nanafy-external-symbol-manually.c 
	gcc $(CFLAGS) -c src/register-nanafy-external-symbol-manually.c -o compiled/register-nanafy-external-symbol-manually.o

compiled/register-nanafy-external-symbol.o: src/register-nanafy-external-symbol.c 
	gcc $(CFLAGS) -c src/register-nanafy-external-symbol.c -o compiled/register-nanafy-external-symbol.o

compiled/register-nanafy-symbol-manually.o: src/register-nanafy-symbol-manually.c 
	gcc $(CFLAGS) -c src/register-nanafy-symbol-manually.c -o compiled/register-nanafy-symbol-manually.o

compiled/register-nanafy-symbol.o: src/register-nanafy-symbol.c 
	gcc $(CFLAGS) -c src/register-nanafy-symbol.c -o compiled/register-nanafy-symbol.o

compiled/register-nanafy-private-symbol-manually.o: src/register-nanafy-private-symbol-manually.c 
	gcc $(CFLAGS) -c src/register-nanafy-private-symbol-manually.c -o compiled/register-nanafy-private-symbol-manually.o

compiled/register-nanafy-private-symbol.o: src/register-nanafy-private-symbol.c 
	gcc $(CFLAGS) -c src/register-nanafy-private-symbol.c -o compiled/register-nanafy-private-symbol.o
