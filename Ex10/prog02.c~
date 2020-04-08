#include <stdio.h>
#include <math.h>

int myatoi(char *);

int main()
{
char str2[][20]={"  258.64",
                 " -38B",
                 "+45 678",
                 "B876",
                 "345-67",
                 "+-382",
                 ""};
  int ival, i;

  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("文字列:%s\n", str2[i]);
    printf("読み取り値:%d\n", ival);
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
  
    
