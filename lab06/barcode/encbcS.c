    #include <assert.h>
    #include <stdio.h>
    #include "bclib.h"

    
    
    extern int read(int, char **);
    
    int barcode[BC_WIDTH][BC_NBITS] = {0};
    
    int main2(int argc, char **argv) {
	    read(argc, argv);
	    printBarcode();
	 
	return 0;
    }
    
    
      int read (int argc, char **argv){
      	int w = 1; // index of the word
	int j = 0; //index of a letted in each word
	int i = 0;  //index from whole chars
	for(w = 1; w < argc; ++w){ //read each words
	  for (j = 0 ; argv[w][j];++j,i++){
	    bc_char2bits( argv[w][j], barcode[i]);//read each char
	  }
	}
	return 1;
      }
      int printBarcode(){
	/* print */
	int i; //index from whole chars
	int j;//index of a letted in each words
	  for(i = 0; i<BC_NBITS; ++i){ 
	    for (j = 0 ; j<BC_WIDTH;++j){
	      if(barcode[i][j]==0){printf("%c", ' ');}
	      else{printf("%c", '#');}
		      }
		      printf("\n");
		    }
	return 1;
      }
			     
