#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  FILE *file;
  int lines = 0;
  char line[128];
  int i,j;
  file = fopen(argv[1],"r");
  if (file == 0) printf("The file path specified is not valid\n");
  fgets(line, 128, file);
  while(line[0]!=0){
    line[0] = 0;
    i++;
    fgets(line, 128, file);
  }
  fclose(file);
  file = fopen(argv[1],"r");
  srand(time(NULL));
  int randNum = ((rand()%(i))+1);
  j = randNum;
  while (j!=0){
    j--;
    fgets(line, 128, file);
  }
  printf("%d: %s",randNum, line);
  return 0;
}