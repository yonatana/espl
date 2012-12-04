#include <stdlib.h>
#include <stdio.h>

/*TODO: add signature for malami */

extern int malami(char* i);
int main(int argc, char **argv) {
	/* TODO: call malami */
    printf("now it works, see: %d is the answer\n",malami(argv[1]));
	return 0;
}
