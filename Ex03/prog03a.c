#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main()
{
  char buf[MAX];
  int  i, n, c;
  FILE *fp, *fpout;

  /* file open */
  if((fp = fopen("data.in","r"))== NULL){
    printf("Cannot open file data.in\n");
    exit(2);
  }
  if((fpout = fopen("data03.out","w"))== NULL){
    printf("Cannot open file data3.out\n");
    exit(2);
  }

  /* data input */
  for(n = 0 ; n < MAX ; n++){
    if((c = fgetc(fp)) == EOF) break;
    buf[n] = (char)c;
  }
  if(n == MAX){
    printf("Buffer overflow !\n");
    exit(3);
  }

  /* data output 逆順に出力　最後の改行は出力しない */
  for(i = n - 2 ; i >= 0 ; i--){
    fputc(buf[i],fpout);
  }
  printf("\n");

  /* file close */
  fclose(fp);
  fclose(fpout);

  return 0;
}
