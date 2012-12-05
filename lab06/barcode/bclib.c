  #include <assert.h>
  #include <stdio.h>
  #include "bclib.h"


  /* TODO: implement bc_char2bits */

  int bc_bits2char(int *bits) {
	  int ch = 0;
	  int i;

	  for(i = BC_NBITS;  i!=0;) { --i;
		  ch = (ch<<1) | bits[i];
	  }

	  return ch;
  }
  int *bc_char2bits(int ch, int *bits){
	  //printf("char2bits");
	  int i;
	  
	  for(i = 0;  i!=BC_NBITS; ++i) {
		  
	  bits[i] = ch%2;
	  //printf("bits is: %d \n",bits[i]);
		  ch = ch/2;
	  }

	  return bits;
  }

  #ifndef TESTBC
  #define TESTBC 0
  #endif

  #if TESTBC
  /** Testing */

  /* converts ch to itself via bits, for testing */
  static int char2char(int ch) {
  printf("char2cahr\n");	
    int bits[BC_NBITS];

	  return bc_bits2char(bc_char2bits(ch, bits));
  }

  void bc_test() {
    printf("bc_test\n");
	  int bits[BC_NBITS] = {0, 0, 0, 0, 0, 1, 0, 0};
    
	   printf("assert 1\n");
	  assert(bc_bits2char(bits)==' ');
	  printf("assert 2\n");
	  assert(char2char(0)==0);
	  printf("assert 3\n");
	  assert(char2char(' ')==' ');
	  printf("assert end\n");
  }

  int main() {
     printf("bclip_main\n");
	  bc_test();
	  return 0;
  }
  #endif
