.PHONY: all clean
.SUFFIXES: .c .o .h .asm

CFLAGS=-g -m32 -O0
LDFLAGS=$(CFLAGS)


%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<

all: scmpa

scmp: scmp.o cmpstr.o
	gcc -m32 -o $@ $^

scmpa: scmpfinal.o cmpstrfinal.o
	gcc -m32 -o $@ $^


clean:
	rm -f *.o