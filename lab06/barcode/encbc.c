    #include <assert.h>
    #include <stdio.h>
    #include "bclib.h"

    int main(int argc, char **argv) {
	 printf("encbc_main\n");    
      char line[argc]; /* buffer for reading and writing */
	    int barcode[BC_WIDTH][BC_NBITS] = {0};
	    int i, j, w;
	    
	    //printf("main\n");
	    /* read */
	    w = 1; // index of the word
	    j = 0; //index of a letted in each word
	    i = 0; //index from whole chars
		    for(w = 1; w < argc; ++w){ //read each words
		      for (j = 0 ; argv[w][j];++j,i++){
		      bc_char2bits( argv[w][j], barcode[i]);//read each char
		      }
		    }
			     
	    
	/* print */
		    for(i = 0; i<BC_NBITS; ++i){ 
		      for (j = 0 ; j<BC_WIDTH;++j){
			if(barcode[i][j]==0){printf("%c", ' ');}
			else{printf("%c", '#');}
		      }
		      printf("\n");
		    }
	    
      
	return 0;
    }