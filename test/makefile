
export CFLAGS += -I$(CURDIR)

default:

clean:
	make clean -C nanafy-array
	make clean -C nanafy-list
	make clean -C nanafy-buffer
	make clean -C nanafy-memory
	make clean -C nanafy-uninited-memory
	make clean -C nanafy-symname-table
	make clean -C nanafy-symbol
	make clean -C nanafy-symbol-list
	make clean -C nanafy-relocation
	make clean -C nanafy-relocation-list
	make clean -C nanafy-section
	make clean -C nanafy-local-relocation
	make clean -C nanafy-local-relocation-list
	make clean -C nanafy
	make clean -C compile

test:
	make test -C nanafy-array
	make test -C nanafy-list
	make test -C nanafy-buffer
	make test -C nanafy-memory
	make test -C nanafy-uninited-memory
	make test -C nanafy-symname-table
	make test -C nanafy-symbol
	make test -C nanafy-symbol-list
	make test -C nanafy-relocation
	make test -C nanafy-relocation-list
	make test -C nanafy-section
	make test -C nanafy-local-relocation
	make test -C nanafy-local-relocation-list
	make test -C nanafy
	make test -C compile
