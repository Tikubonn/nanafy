
default:

clean:
	rm -f nanafy-remap.h
	rm -f nanafy-remap.lib
	rm -f compiled/remap-nanafy-data-memory.o
	rm -f compiled/remap-nanafy-local-relocation-list.o
	rm -f compiled/remap-nanafy-text-relocation-list.o
	rm -f compiled/remap-nanafy-rodata-memory.o
	rm -f compiled/remap-nanafy-symbol-list.o
	rm -f compiled/remap-nanafy-symname-table.o
	rm -f compiled/remap-nanafy-text-memory.o
	rm -f compiled/remap-nanafy-data-relocation-list.o
	rm -f compiled/remap-nanafy-rodata-relocation-list.o

nanafy-remap.h: src/remap-nanafy-data-memory.h src/remap-nanafy-local-relocation-list.h src/remap-nanafy-text-relocation-list.h src/remap-nanafy-rodata-memory.h src/remap-nanafy-symbol-list.h src/remap-nanafy-symname-table.h src/remap-nanafy-text-memory.h src/remap-nanafy-data-relocation-list.h src/remap-nanafy-rodata-relocation-list.h
	cat src/remap-nanafy-data-memory.h src/remap-nanafy-local-relocation-list.h src/remap-nanafy-text-relocation-list.h src/remap-nanafy-rodata-memory.h src/remap-nanafy-symbol-list.h src/remap-nanafy-symname-table.h src/remap-nanafy-text-memory.h src/remap-nanafy-data-relocation-list.h src/remap-nanafy-rodata-relocation-list.h > nanafy-remap.h

nanafy-remap.lib: compiled/remap-nanafy-data-memory.o compiled/remap-nanafy-local-relocation-list.o compiled/remap-nanafy-text-relocation-list.o compiled/remap-nanafy-rodata-memory.o compiled/remap-nanafy-symbol-list.o compiled/remap-nanafy-symname-table.o compiled/remap-nanafy-text-memory.o compiled/remap-nanafy-data-relocation-list.o compiled/remap-nanafy-rodata-relocation-list.o
	ar r nanafy-remap.lib compiled/remap-nanafy-data-memory.o compiled/remap-nanafy-local-relocation-list.o compiled/remap-nanafy-text-relocation-list.o compiled/remap-nanafy-rodata-memory.o compiled/remap-nanafy-symbol-list.o compiled/remap-nanafy-symname-table.o compiled/remap-nanafy-text-memory.o compiled/remap-nanafy-data-relocation-list.o compiled/remap-nanafy-rodata-relocation-list.o

compiled/remap-nanafy-data-memory.o: src/remap-nanafy-data-memory.c 
	gcc $(CFLAGS) -c src/remap-nanafy-data-memory.c -o compiled/remap-nanafy-data-memory.o

compiled/remap-nanafy-local-relocation-list.o: src/remap-nanafy-local-relocation-list.c 
	gcc $(CFLAGS) -c src/remap-nanafy-local-relocation-list.c -o compiled/remap-nanafy-local-relocation-list.o

compiled/remap-nanafy-text-relocation-list.o: src/remap-nanafy-text-relocation-list.c 
	gcc $(CFLAGS) -c src/remap-nanafy-text-relocation-list.c -o compiled/remap-nanafy-text-relocation-list.o

compiled/remap-nanafy-rodata-memory.o: src/remap-nanafy-rodata-memory.c 
	gcc $(CFLAGS) -c src/remap-nanafy-rodata-memory.c -o compiled/remap-nanafy-rodata-memory.o

compiled/remap-nanafy-symbol-list.o: src/remap-nanafy-symbol-list.c 
	gcc $(CFLAGS) -c src/remap-nanafy-symbol-list.c -o compiled/remap-nanafy-symbol-list.o

compiled/remap-nanafy-symname-table.o: src/remap-nanafy-symname-table.c 
	gcc $(CFLAGS) -c src/remap-nanafy-symname-table.c -o compiled/remap-nanafy-symname-table.o

compiled/remap-nanafy-text-memory.o: src/remap-nanafy-text-memory.c 
	gcc $(CFLAGS) -c src/remap-nanafy-text-memory.c -o compiled/remap-nanafy-text-memory.o

compiled/remap-nanafy-data-relocation-list.o: src/remap-nanafy-data-relocation-list.c 
	gcc $(CFLAGS) -c src/remap-nanafy-data-relocation-list.c -o compiled/remap-nanafy-data-relocation-list.o

compiled/remap-nanafy-rodata-relocation-list.o: src/remap-nanafy-rodata-relocation-list.c 
	gcc $(CFLAGS) -c src/remap-nanafy-rodata-relocation-list.c -o compiled/remap-nanafy-rodata-relocation-list.o
