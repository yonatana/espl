#include <stdio.h>
#include <unistd.h>

/*
 * the program takes 2 files, check bytes by bytes that they are the same
 */
int main(int argc, char **argv)
{
    FILE *fileOld, *fileNew;
    int opt;
    
    const char charBufferOld [1];
    const char charBufferNew [1];
    int bytesRead = 1;
    int numberOfDiffrencesToPrint=1;

 
    
    
   /*   printf("%s %s\n",argv[1],argv[2]);
    while(fread(&charBufferOld,1,1,fileOld) && fread(&charBufferNew,1,1,fileNew))
		{
		  if(charBufferOld[0]!=charBufferNew[0]){
		    printf("Bytes %i -%i +%i\n",bytesRead,charBufferOld[0],charBufferNew[0]);
		  }
		bytesRead++;
		}
		fclose(fileOld);
		fclose(fileNew);
      
    
		if(fileOld == NULL){
		printf("fileOld was null\n");
		}
    */
    printf ("starts with argc%i: \n",argc);
    //opt function
    while ((opt = getopt(argc, argv,"n:hq")) != -1) {
      printf ("while\n");
        switch (opt) {
	  printf ("switch\n");
             case 'n' : //print first number whos differ
	        fileOld = fopen(argv[optind],"r");
		fileNew = fopen(argv[optind+1],"r");
		printf ("case n,argc:%i argv[1]: %s argv[2]: %s\n",argc, argv[optind],argv[optind+1]);
		numberOfDiffrencesToPrint = atoi(optarg);
		if(fileOld == NULL){
		printf("fileOld was null\n");
		}
		if(fileNew == NULL){
		printf("fileNew was null\n");
		}
		if(fileOld != NULL && fileNew != NULL ){//if the opening was successful
		 while(fread(&charBufferOld,1,1,fileOld) && fread(&charBufferNew,1,1,fileNew) && numberOfDiffrencesToPrint)
		{
		  if(charBufferOld[0]!=charBufferNew[0]){
		    printf("Bytes %i -%i +%i\n",bytesRead,charBufferOld[0],charBufferNew[0]);
		    numberOfDiffrencesToPrint--;
		  }
		bytesRead++;
		}
		fclose(fileOld);
		fclose(fileNew);
		}
		else{//couldent open the files
		printf ("one of the files was broke\n");
		  }
                 break;
             case 'h' : //print a summery of options
                  printf ("case h\n");
		  printf("-n NUMBER  print first NUMBER differences and exit\n"); 
		  printf("-q do not print out the differences, exist with code 0 if the files are identical, 1 otherwise\n");

	      break;
             case 'q' : //print o if the files identical and 1 otherwise
		printf ("case q\n");
		fileOld = fopen(argv[optind],"r");
		fileNew = fopen(argv[optind+1],"r");
    
		if(fileOld != NULL && fileNew != NULL ){//if the opening was successful
			
		while(fread(&charBufferOld,1,1,fileOld) && fread(&charBufferNew,1,1,fileNew) && bytesRead)
		{
		  if(charBufferOld[0]!=charBufferNew[0]){
		  bytesRead=0;
		  }
		}
		printf("%i\n",bytesRead);
		
		fclose(fileOld);
		fclose(fileNew);
	       }
	       else{//couldent open the files
		printf ("one of the files was broke\n");
		  }
                 break;
	
             default:
	       printf ("default\n");
	       fileOld = fopen(argv[optind],"r");
	       fileNew = fopen(argv[optind+1],"r");
    
	       if(fileOld != NULL  && fileNew !=NULL  ){//if the opening was successful
      
		while(fread(&charBufferOld,1,1,fileOld) && fread(&charBufferNew,1,1,fileNew))
		{
		  if(charBufferOld[0]!=charBufferNew[0]){
		    printf("Bytes %i -%i +%i\n",bytesRead,charBufferOld[0],charBufferNew[0]);
		  }
		bytesRead++;
		}
		fclose(fileOld);
		fclose(fileNew);
	      }
	      else{//couldent open the files
		  printf ("one of the files was broke\n");
	      }
	  }
    }
  
return 0;
}