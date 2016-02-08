#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define LINELENGTH 80

char getrandchar(){
  int random_number = (int)(rand() % 94 +32);
  char c = random_number;
  return c;
   
}

int main(int argc, char* argv[]){
  FILE *f = fopen("junk", "w");
  if (!f){
    return 1;
  }
  int i;char c; 
  srand(time(NULL));

   for(i = 0; i<MAX;i++){
       if (i>0 && i%LINELENGTH == 0){
           fprintf(f,"\n");
         }
       fprintf(f,"%c", getrandchar());
    }
   fclose(f);
  
}
