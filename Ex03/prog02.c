#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(){
  double yomikomi;
  double saidai=0;
  double saisyou=DBL_MAX;
  int result;
  FILE *fp, *fpout;

  fp=fopen("rand.in","r");
  if(fp==NULL){
    printf("File open error!\n");
    exit(1);
  }
  fpout=fopen("rand.out","w");
  if(fp==NULL){
    printf("File open error!\n");
    exit(2);
  }
  
  while(1){
    result=fscanf(fp,"%lf",&yomikomi);
    if(result==EOF) break;
    
    if(yomikomi>=saidai) saidai=yomikomi;
    else if(yomikomi<=saisyou) saisyou=yomikomi;
  }

  fprintf(fpout,"max=%f,min=%f",saidai,saisyou);

  fclose(fpout);
  fclose(fp);
  return 0;
}
