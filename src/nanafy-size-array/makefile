
default:

clean:
	rm -f nanafy-size-array.lib
	rm -f nanafy-size-array.o

nanafy-size-array.lib: nanafy-size-array.o
	ar r nanafy-size-array.lib nanafy-size-array.o

nanafy-size-array.o: nanafy-size-array.c
	gcc $(CFLAGS) -c nanafy-size-array.c -o nanafy-size-array.o
