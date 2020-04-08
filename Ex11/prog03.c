#include <stdio.h>
#define N 10

typedef struct {
  int map[N][N];
  int step;
  int msize, nsize;
} SMAP;

void routing(int, int, SMAP);
void mapprint(SMAP);

int pat=0; /* ゴールに到達したパターン数を記録するための外部変数 */

int main()
{
  SMAP smap;
  int i,j;

  printf("マスのサイズを入力して下さい(msize, nsize):\n");
  scanf("%d%d", &smap.msize, &smap.nsize);

  /* smapの初期化 */
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      smap.map[i][j]=0;
  smap.step=1;

  routing(smap.msize-1,smap.nsize-1,smap); /* msize-1, nsize-1から探索開始 */

  return 0;
}

void routing(int m, int n, SMAP smap)
{
  /* まずm, n がマップ（マス）外なら即return */
  /* m,nが0,0ならゴールなので、pat++し、マップ表示して、return */
  /* m,nの位置に数値があれば、なにもせずにreturn */
  /* m,nの位置が0ならstepを代入し、step++ */
  /* m,nの周辺４方向について、再度routingを呼び出す */
  /* 注）一般に配列は[縦][横]で使うが、 m,nはマスの
  　　　 横、縦を表すので、整合性に注意して下さい */

  int i,j;

  if(m>=smap.msize||n>=smap.nsize){
    return;
  }
  else if(m<0||n<0){
    return;
  }
  else if(m==0&&n==0){
    smap.map[0][0]=smap.step;
    pat++;
    mapprint(smap);
    return;
  }
  else if(smap.map[n][m]!=0){
    return;
  }
  else if(smap.map[n][m]==0){
    smap.map[n][m]=smap.step;
    smap.step++;
  }

  routing(m,n+1,smap);
  routing(m+1,n,smap);
  routing(m-1,n,smap);
  routing(m,n-1,smap);
  
}

void mapprint(SMAP smap)
{

  int i,j;
  
  printf("パターン:%d,　経路長:%d\n", pat, smap.step);

  for (i=0; i<smap.nsize; i++){
    for (j=0; j<smap.msize; j++){
      printf("%2d ", smap.map[i][j]);
    }
    printf("\n");
  }

}
