#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int isAlpha(char);
int isUpper(char);

int main(void){

  char c;

  printf("(複数の)文字を入力してください:");
  while(1){
    scanf("%c",&c);
    printf("\n");
    if(c=='\n') break;
    if(c!='\n'){
      if(isAlpha(c)==1){
	if(isUpper(c)==1) printf("文字 '%c' のアスコーコードは%d(0x%x)で，アルファベット大文字です.\n",c,c,c);
	else if(isUpper(c)==0) printf("文字 '%c' のアスコーコードは%d(0x%x)で，アルファベット小文字です.\n",c,c,c);
      }
      else if(isAlpha(c)==0){
	printf("文字 '%c' のアスコーコードは%d(0x%x)で，アルファベットではありません.．\n",c,c,c);
      }
    }
  }
  
  return 0;
}

int isAlpha(char c){
  if( (c>='a'&& c<='z') || (c>='A' && c<='Z'))
    return TRUE;
  else
    return FALSE;
}

int isUpper(char c){
  if(c>='A' && c<='Z')
    return TRUE;
  else
    return FALSE;
}
