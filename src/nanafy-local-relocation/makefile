
default:

clean:
	rm -f nanafy-local-relocation.h
	rm -f nanafy-local-relocation.lib
	rm -f compiled/init-nanafy-local-relocation.o
	rm -f compiled/fix-nanafy-memory-with-local-relocation.o
	rm -f compiled/same-nanafy-local-relocation-placep.o

nanafy-local-relocation.h: src/init-nanafy-local-relocation.h src/fix-nanafy-memory-with-local-relocation.h src/same-nanafy-local-relocation-placep.h 
	cat src/init-nanafy-local-relocation.h src/fix-nanafy-memory-with-local-relocation.h src/same-nanafy-local-relocation-placep.h > nanafy-local-relocation.h

nanafy-local-relocation.lib: compiled/init-nanafy-local-relocation.o compiled/fix-nanafy-memory-with-local-relocation.o compiled/same-nanafy-local-relocation-placep.o 
	ar r nanafy-local-relocation.lib compiled/init-nanafy-local-relocation.o compiled/fix-nanafy-memory-with-local-relocation.o compiled/same-nanafy-local-relocation-placep.o 

compiled/init-nanafy-local-relocation.o: src/init-nanafy-local-relocation.c 
	gcc $(CFLAGS) -c src/init-nanafy-local-relocation.c -o compiled/init-nanafy-local-relocation.o

compiled/fix-nanafy-memory-with-local-relocation.o: src/fix-nanafy-memory-with-local-relocation.c 
	gcc $(CFLAGS) -c src/fix-nanafy-memory-with-local-relocation.c -o compiled/fix-nanafy-memory-with-local-relocation.o

compiled/same-nanafy-local-relocation-placep.o: src/same-nanafy-local-relocation-placep.c 
	gcc $(CFLAGS) -c src/same-nanafy-local-relocation-placep.c -o compiled/same-nanafy-local-relocation-placep.o
