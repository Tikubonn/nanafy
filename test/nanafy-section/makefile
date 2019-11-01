
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean:
	rm -f nanafy-section.h
	rm -f compiled/test-nanafy-section.o

test:
	make nanafy-section.exe
	./nanafy-section.exe

nanafy-section.exe: main.c compiled/test-nanafy-section.o nanafy.h nanafy.dll
	gcc $(CFLAGS) main.c compiled/test-nanafy-section.o -lnanafy -o nanafy-section.exe

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

compiled/test-nanafy-section.o: src/test-nanafy-section.c nanafy.h nanafy.dll
	gcc $(CFLAGS) -c src/test-nanafy-section.c -o compiled/test-nanafy-section.o
