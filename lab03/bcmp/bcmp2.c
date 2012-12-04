int main(int argc, char **argv)
{
    FILE *fileOld, *fileNew;
    int opt;
    
    const char charBufferOld [1];
    const char charBufferNew [1];
    int bytesRead = 1;
    int numberOfDiffrencesToPrint=1;

 
    
    
   /  printf("%s %s\n",argv[1],argv[2]);
    while(fread(&charBufferOld,1,1,fileOld) && fread(&charBufferNew,1,1,fileNew))
		{
		  if(charBufferOld[0]!=charBufferNew[0]){
		    printf("Bytes %i -%i +%i\n",bytesRead,charBufferOld[0],charBufferNew[0]);
		  }
		bytesRead++;
		}
		fclose(fileOld);
		fclose(fileNew);
      
    return 0;
}
    