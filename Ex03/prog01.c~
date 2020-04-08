#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1000

char tolowr(char c); 
char toupr(char c); 

int main(){
  FILE *fpin, *fpout;
  char buf[MAX];
  char buf2[MAX];
  int c,n,i;
  
  fpin=fopen("data.in","r");
  
  if(fpin == NULL){
    printf("read file open error\n");
    exit(1);
  }

  fpout=fopen("out.dat","w");

    
  if(fpout== NULL){
    printf("read file open error\n");
    exit(1);
  }

  for(n=0;n<MAX;n++){
    c=fgetc(fpin);
    if(c==EOF) break;
    buf[n]=(char)c;
  }

  for(i=0;i<MAX;i++){
    buf[i] = buf[i];
  }

  for(i=0;i<n-2;i++){
    fprintf(fpout,"%c",buf[i]);
  }

  for(i=0;i<n-2;i++){
    if(97<=buf[i]&&buf[i]<=122){
      buf[i]=c;
      i=tolowr(c);
    }
  }
  
  for(i=0;i<n-2;i++){
    fprintf(fpout,"%c",buf[i]);
  }

  for(i=0;i<n-2;i++){
    if(97<=buf2[i]&&buf2[i]<=122){
      buf[i]=c;
      i=tolowr(c);
    }
    else if(65<=buf2[i]&&buf2[i]<=90){
      buf2[i]=c;
      i=toupr(c);
    }
  }

  for(i=0;i<n-2;i++){
    fprintf(fpout,"%c",buf2[i]);
  }


  fclose(fpout);
  fclose(fpin);

  return 0;
}

char tolowr(char c) {
  return (c + 0x20);
}

char toupr(char c) {
  return (c - 0x20);
}
