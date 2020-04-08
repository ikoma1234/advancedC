#include <stdio.h>
#define N 5
#define EMPTY -1
#define FULL  -2

int func(int);

int main()
{
  int n, r;

  while (1) {
    printf("数値を入力して下さい (正：格納，負：取出，0：終了): ");
    scanf("%d", &n);
    if (n == 0) break; /* 終了 */
    r = func(n); /* 格納または取出 */
    func(0); /* 表示 */
    if (r > 0) printf("取り出したデータ: %d\n", r); /* 取得データの表示 */
    else if (r == EMPTY) printf("エラー（スタックが空です）\n"); 
    else if (r == FULL ) printf("エラー（スタックが満杯です）\n"); 
  }
  return 0;
}

/* 
[引数]
正の整数: 格納，負の整数: 取出，0: 表示
[戻り値]
格納の場合) スタックが満杯: マクロ定数 FULL，それ以外: 0
取出の場合) スタックが空: マクロ定数 EMPTY，それ以外: 取り出した値
表示の場合) 0
*/
int func(int x)
{
  static int stack[N]; /* データを格納する配列 */
  static int size = 0; /* データ数 */
  int j;
  
  if(x>0){
    if(size==N) return FULL;
    else{
      stack[size]=x;
      size++;
      return 0;
    }
  }
  else if(x==0){
    printf("size=%d[",size);
    for(j=0;j<size;j++) printf("%d ",stack[j]);
    printf("]\n");
      return 0;
  }
  else{
    if(size==0) return EMPTY;
    else{
      size--;
      return stack[size];
    }
  }
}
