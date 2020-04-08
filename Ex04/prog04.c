#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 99999

int main(){

  char str[MAX],jisho[MAX];
  char *p,*jishop;
  int status,x=0;
  FILE *fp;

  while(1){

    x=0;
    
  fp=fopen("/home/course/prog1/public_html/2018/ex/ex04/words.txt","r");
  if(fp==NULL){
    printf("Cannot open file.\n");
    exit(1);
  }

  printf("Input a word:");
  status=scanf("%s",str);
  if(status==-1) break;
  
  p=str;

  while(1){
    
    status=fscanf(fp,"%s",jisho);
    if(status==-1) break;
    
    jishop=jisho;

    if(strcmp(p,jishop)==0){
      printf("The word %s is found.\n", p);
      x=1;
      fclose(fp);
    }
  }
  
  if(x==0){
  printf("The word %s is not found.\n", p);
  }
  fclose(fp);
  
  }
  
  return 0;
}

  
  
