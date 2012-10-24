#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv) {
	char line[argc]; /* buffer for reading and writing */
	char bits[BC_NBITS];//will represent a char
	int barcode[BC_WIDTH][BC_NBITS] = {0};
	int i, j, w;
	
	/* read */
	j = 0; //index of a letted in each word
	i = 0; //index from whole chars
		for(w = 1; w < argc; ++w, ++i){ //read each words
		  for (j = 0 ; argv[w][j];++j, ++i){
		  bc_char2bits( argv[w][j], barcode[i]);//read each char
		  
	}
			
	
    /* print */
	printf("%s\n", line);
   
    return 0;
}