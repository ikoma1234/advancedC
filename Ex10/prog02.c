#include <stdio.h>
#include <math.h> // -lm をつけてコンパイル 
#include <stdlib.h>

int myatoi(char *);

int main()
{

  char wareki[20];
  int ival;
  
  printf("和暦（H11等）:");
  scanf("%s",wareki);
  ival = myatoi(&wareki[1]);
 
  switch(wareki[0]) {
  case 'M' :
    printf(" Year (A.D.): %d\n", ival+1867);
    break;
  case 'T' :
    printf(" Year (A.D.): %d\n", ival+1911);
    break;
  case 'S' :
    printf(" Year (A.D.): %d\n", ival+1925);
    break;
  case 'H' :
    printf(" Year (A.D.): %d\n", ival+1988);
    break;
  default:
    printf("数字を読み取れません\n");
    exit(2);
  }

 
  
  return 0;
}
/* この後に関数 myatoi を作成する */
int myatoi(char *str){

  int i,j=0,k, seisuu=0, minus=0, seisuuh[20], err=0;

  for(i=0;str[i]==32;i++){
  }
 
  if(str[i]==45){
    minus=1;
    i++;
    if(str[i]==45||str[i]==43){
      err=1;
      goto label;
    }
  }

  if(str[i]==43){
    i++;
  }

  if(str[i]<48||57<str[i]){
    err=1;
    goto label;
  }

  
  while(47<str[i]&&str[i]<58){
    seisuuh[j]=str[i]-48;
    j++;
    i++;
  }
  j--;

  for(k=0;k<j+1;k++){
    seisuu+=(int)pow(10,k)*seisuuh[j-k];
  }

  if(minus==1) seisuu*=-1;

  return seisuu;
  
  label:
  if(err==1) seisuu=0;

  return seisuu;
}
  
    
