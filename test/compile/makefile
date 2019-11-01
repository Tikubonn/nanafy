
export CFLAGS += -I$(CURDIR) -L$(CURDIR)

default:

clean: .always
	rm -f nanafy.h
	rm -f return0x25.o
	rm -f readchar.o

test:
	make test-return0x25
	make test-readchar

nanafy.h: $(rootdir)/dist/nanafy.h
	cp $(rootdir)/dist/nanafy.h nanafy.h

nanafy.dll: $(rootdir)/dist/nanafy.dll
	cp $(rootdir)/dist/nanafy.dll nanafy.dll

test-return0x25: .always
	make return0x25.exe
	return0x25.exe temp.o
	gcc temp.o -o temp.exe
	sh return0x25.sh ./temp.exe

test-readchar: .always
	make readchar.exe
	readchar.exe temp.o
	gcc temp.o -o temp.exe
	sh readchar.sh ./temp.exe

return0x25.exe: return0x25.c nanafy.h nanafy.dll
	gcc $(CFLAGS) return0x25.c -lnanafy -o return0x25.exe

readchar.exe: readchar.c nanafy.h nanafy.dll
	gcc $(CFLAGS) readchar.c -lnanafy -o readchar.exe

.always:
