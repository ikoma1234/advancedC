#include <stdio.h>
#define N 256

int main()
{
  char str[N], str_new[N];
  int i;

  printf("Input : ");
  scanf("%s",str);   /* 1単語を標準入力から入力 */

  i = 0;
  while (str[i]!=NULL){
        if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)){
          str_new[i]=str[i];
	}
	else{
	  str_new[i]=32;
	}
        i++;
  }
    /* 単語の最後に達していなければ繰り返す */
    /* 文字が A?Z, a?z ならそのままstr_newにコピー */
    /* 文字がそれ以外ならstr_newに' 'を代入する処理を書く */
    /* その他、ループ関連の処理も */
  str_new[i]='\0';
  /* str_newの末尾の処理も必要 */

  printf("Before : %s\n", str);
  printf("After  : %s\n", str_new);
  return 0;
}
