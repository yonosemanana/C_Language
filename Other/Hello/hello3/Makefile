.PHONY: default

default: hello3

hello3.i: hello3.c
	gcc -E hello3.c -o hello3.i

hello3.s: hello3.i
	gcc -S hello3.c -o hello3.s

hello3.o: hello3.s
	gcc -c hello3.s -o hello3.o

hello3: hello3.o
	ld /usr/lib/x86_64-linux-gnu/crt1.o \
		/usr/lib/x86_64-linux-gnu/crti.o \
		hello3.o \
		-lc \
		/usr/lib/x86_64-linux-gnu/crtn.o \
		-dynamic-linker /lib64/ld-linux-x86-64.so.2 \
		-e _start \
		-o hello3

.PHONY: clean
clean:
	rm -f hello.i hello3.s hello3.o hello3
