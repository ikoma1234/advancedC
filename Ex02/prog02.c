#include <stdio.h>
#define INDI 3
#define INDJ 4

int main()
{
  int a[INDI][INDJ] = {
    { 1,  6, 11,  4},
    { 9,  2,  7,  0},
    { 5, 10,  3,  8},
  };
  int n;
  /* 必要に応じて変数宣言を追加 */
  int i,j;

  printf("数値を入力してください: ");
  scanf("%d", &n);

  for(i=0;i<INDI;i++){
    for(j=0;j<INDJ;j++){
      if(n==a[i][j]){
	goto label;
      }
    }
  }
  printf("2次元配列の要素に%dはありません\n", n);
  return 0;

 label :;
  printf("a[%d][%d]が%dです。\n",i,j,n);
  return 0;

}
