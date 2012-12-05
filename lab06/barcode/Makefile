CC=gcc
CFLAGS=-O -g -m32

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.asm
	nasm -g -O1 -f elf -o $@ $<

all: encbcA decbc test

test: encbcA decbc testbc 
	./testbc
	if [ "`./encbcA shalom olam|./decbc`" != "shalom olam" ]; then\
		exit 1;\
	fi

# TODO: add rule for encbcS
encbcA: encbcA.o encbcS.o bclib.o func.o
	$(CC) $(CFLAGS) -o $@ $^

decbc: decbc.o bclib.o
	$(CC) $(CFLAGS) -o $@ $^

testbc: bclib.c
	$(CC) $(CFLAGS) -o $@ -DTESTBC=1 $^

# TODO: add rule for encbcS.o
encbcS.o: encbcS.c bclib.h
decbc.o: decbc.c bclib.h
bclib.o: bclib.c bclib.h


clean:
	rm -f *.o encbcS decbc testbc
