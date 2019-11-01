
default:

clean:
	rm -f nanafy-buffer.h
	rm -f nanafy-buffer.lib
	rm -f compiled/init-nanafy-buffer.o
	rm -f compiled/put-nanafy-buffer.o
	rm -f compiled/write-nanafy-buffer.o
	rm -f compiled/tell-nanafy-buffer.o
	rm -f compiled/has-nanafy-buffer-margin.o
	rm -f compiled/nanafy-buffer-size.o
	rm -f compiled/nanafy-buffer-array.o
	rm -f compiled/copy-nanafy-buffer.o
	rm -f compiled/extend-nanafy-buffer.o
	rm -f compiled/free-nanafy-buffer.o

nanafy-buffer.h: src/init-nanafy-buffer.h src/put-nanafy-buffer.h src/write-nanafy-buffer.h src/tell-nanafy-buffer.h src/has-nanafy-buffer-margin.h src/nanafy-buffer-size.h src/nanafy-buffer-array.h src/copy-nanafy-buffer.h src/extend-nanafy-buffer.h src/free-nanafy-buffer.h
	cat src/init-nanafy-buffer.h src/put-nanafy-buffer.h src/write-nanafy-buffer.h src/tell-nanafy-buffer.h src/has-nanafy-buffer-margin.h src/nanafy-buffer-size.h src/nanafy-buffer-array.h src/copy-nanafy-buffer.h src/extend-nanafy-buffer.h src/free-nanafy-buffer.h > nanafy-buffer.h

nanafy-buffer.lib: compiled/init-nanafy-buffer.o compiled/put-nanafy-buffer.o compiled/write-nanafy-buffer.o compiled/tell-nanafy-buffer.o compiled/has-nanafy-buffer-margin.o compiled/nanafy-buffer-size.o compiled/nanafy-buffer-array.o compiled/copy-nanafy-buffer.o compiled/extend-nanafy-buffer.o compiled/free-nanafy-buffer.o
	ar r nanafy-buffer.lib compiled/init-nanafy-buffer.o compiled/put-nanafy-buffer.o compiled/write-nanafy-buffer.o compiled/tell-nanafy-buffer.o compiled/has-nanafy-buffer-margin.o compiled/nanafy-buffer-size.o compiled/nanafy-buffer-array.o compiled/copy-nanafy-buffer.o compiled/extend-nanafy-buffer.o compiled/free-nanafy-buffer.o

compiled/init-nanafy-buffer.o: src/init-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/init-nanafy-buffer.c -o compiled/init-nanafy-buffer.o

compiled/put-nanafy-buffer.o: src/put-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/put-nanafy-buffer.c -o compiled/put-nanafy-buffer.o

compiled/write-nanafy-buffer.o: src/write-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/write-nanafy-buffer.c -o compiled/write-nanafy-buffer.o

compiled/tell-nanafy-buffer.o: src/tell-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/tell-nanafy-buffer.c -o compiled/tell-nanafy-buffer.o

compiled/has-nanafy-buffer-margin.o: src/has-nanafy-buffer-margin.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/has-nanafy-buffer-margin.c -o compiled/has-nanafy-buffer-margin.o

compiled/nanafy-buffer-size.o: src/nanafy-buffer-size.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/nanafy-buffer-size.c -o compiled/nanafy-buffer-size.o

compiled/nanafy-buffer-array.o: src/nanafy-buffer-array.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/nanafy-buffer-array.c -o compiled/nanafy-buffer-array.o

compiled/copy-nanafy-buffer.o: src/copy-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/copy-nanafy-buffer.c -o compiled/copy-nanafy-buffer.o

compiled/extend-nanafy-buffer.o: src/extend-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/extend-nanafy-buffer.c -o compiled/extend-nanafy-buffer.o

compiled/free-nanafy-buffer.o: src/free-nanafy-buffer.c nanafy-buffer.h
	gcc $(CFLAGS) -c src/free-nanafy-buffer.c -o compiled/free-nanafy-buffer.o
