all: secret-dec secret-enc
secret-dec: secret-elf-a secret-elf-c
	gcc -m32 -o $@ $^
secret-enc: secret-elf-b secret-elf-c
	gcc -m32 -o $@ $^