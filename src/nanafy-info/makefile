
default:

clean:
	rm -f nanafy-info.h
	rm -f nanafy-info.lib
	rm -f compiled/setup-nanafy-info-for-x86.o
	rm -f compiled/setup-nanafy-info-for-x64.o
	rm -f compiled/find-nanafy-relocation-info.o

nanafy-info.lib: compiled/setup-nanafy-info-for-x86.o compiled/setup-nanafy-info-for-x64.o compiled/find-nanafy-relocation-info.o
	ar r nanafy-info.lib compiled/setup-nanafy-info-for-x86.o compiled/setup-nanafy-info-for-x64.o compiled/find-nanafy-relocation-info.o

nanafy-info.h: src/setup-nanafy-info-for-x86.h src/setup-nanafy-info-for-x64.h src/find-nanafy-relocation-info.h
	cat src/setup-nanafy-info-for-x86.h src/setup-nanafy-info-for-x64.h src/find-nanafy-relocation-info.h > nanafy-info.h

compiled/setup-nanafy-info-for-x86.o: src/setup-nanafy-info-for-x86.c 
	gcc $(CFLAGS) -c src/setup-nanafy-info-for-x86.c -o compiled/setup-nanafy-info-for-x86.o

compiled/setup-nanafy-info-for-x64.o: src/setup-nanafy-info-for-x64.c 
	gcc $(CFLAGS) -c src/setup-nanafy-info-for-x64.c -o compiled/setup-nanafy-info-for-x64.o

compiled/find-nanafy-relocation-info.o: src/find-nanafy-relocation-info.c 
	gcc $(CFLAGS) -c src/find-nanafy-relocation-info.c -o compiled/find-nanafy-relocation-info.o
