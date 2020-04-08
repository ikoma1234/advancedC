#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main()
{
  char buf[MAX],bufan[MAX];
  int  i, n, c;
  FILE *fpout,*fpan;

  /* file open */
  if((fpout = fopen("data03.out","r"))== NULL){
    printf("Cannot open file data03.out\n");
    exit(2);
  }
  if((fpan = fopen("data03_answer.out","r"))== NULL){
    printf("Cannot open file data03answer.out\n");
    exit(2);
  }
  
  /* data input */
  for(n = 0 ; n < MAX ; n++){
    if((c = fgetc(fpout)) == EOF) break;
    buf[n] = (char)c;
  }
  if(n == MAX){
    printf("Buffer overflow !\n");
    exit(3);
  }
  for(n = 0 ; n < MAX ; n++){
    if((c = fgetc(fpan)) == EOF) break;
    bufan[n] = (char)c;
  }
  if(n == MAX){
    printf("Buffer overflow !\n");
    exit(3);
  }

  for(i=0;i<n;i++){
    if(buf[i]!=bufan[i]) goto label;
  }
  /* file close */
  fclose(fpout);
  fclose(fpan);
  printf("Two files are identical.\n");
  
  return 0;

 label: printf("Two files are different at %d byte.\n",i);
  return 0;
}
