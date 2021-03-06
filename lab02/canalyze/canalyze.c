      #include <stdio.h>
      #include "fgetname.h"
      #include "namelist.h"
      /*get files and print names from those files*/
      char  *savedWords [] ={"auto","double", "int","long", "breake", "else","long", "switch", "case", "enum","register","typedof", "char","extern","return", "union","const","flout","short","unsigned","continue","for","signed","void","defult","goto","sizeof","volatile","do","if","static","while"};
      
      int compare (const void* a, const void* b);
      
      int legalName(char *name);
      
      int main (int argc, char **argv){
      //varibales
      namelist nl = make_namelist();  
      FILE *stream; 
      char *fileName;
      char name[64];
      int FLAG = 0;
      int i = 1;
      int j = 0;     
      
      //upload files in a loop and gets the name to an array
    for (i=1;i!=argc;i++){//each file
     fileName = argv[i];//get the file
     stream = fopen(fileName, "r");//read the file
     
     while(fgetname(name, sizeof(name), stream)) {
       if(legalName(name)){
       printf("%s ", name);
	add_name(nl, name);
	//printf("\n");
	}
     }
     fclose(stream);
      }
      qsort(nl->names,nl->size,sizeof(struct namestat),compare);
  
  for(i=0;i<nl->size;i++){
    printf("%s %d\n",nl->names[i].name,nl->names[i].count);
  }
  
   
      return 0;
      }
      
      int legalName(char *name){
      int t=0;
      int flag=1;
	for(t=0;t<32&&flag!=0;t++){
	flag = strcmp(name,savedWords[t]);
	}
      return flag;
      }
int compare(const void *p1, const void *p2)
      {
          return strcmp(((struct namestat *)p1)->name, ((struct namestat*)p2)->name);
       }
    