#include <stdio.h>
#include <stdlib.h>

int main(void){

  char c;
  int i=0;

  printf("(複数の)文字を入力してください:");
  while(1){
    scanf("%c",&c);
    printf("\n");
    if(c=='\n') break;
    if(c!='\n')  printf("文字 '%c' のアスコーコードは%d(0x%x)です.\n",c,c,c); 
  }
  
  return 0;
}
