#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BLACK '1'
#define WHITE '0'

#define PI 3.14159265358979323846264338

char **pbm_alloc(int, int);
void   pbm_free(char **, int, int);
char **pbm_read(int *x, int *y);
void   pbm_write(char **, int, int);
void   pbm_circle(char **, int, int, int, char);

char *odata;

int main() {
  char **pbm;
  int i;
  int ix, iy, r;

  /* 標準入力から入力された画像に合わせて領域を確保し、画素を読み込む */
  pbm = pbm_read(&ix, &iy);

  /* 外周円の半径を画像サイズに合わせて決める */
  if (ix>iy) r = iy / 2;
  else r = ix / 2;

  r--;

  /* 円を書く */
  pbm_circle(pbm, ix, iy, r, '1');
  pbm_circle(pbm, ix, iy, r/2, '1');

  /* 画像を書きだす */
  pbm_write(pbm, ix, iy);
  /* 画像領域の解放 */
  pbm_free(pbm, ix, iy);
  return 0;
}

char **pbm_alloc(int x, int y) {

  int i, j;
  char **data;
  
  
  /* ２次元配列の作成 */
  data = malloc(sizeof(char *) * y);
  odata = malloc(sizeof(char) * x * y);
  /* 画素数が多すぎる場合 */
  if (odata == NULL){
    free(data);
    return NULL;
  }

  /* ２次元配列の設定 */
  for(i = 0; i < y; i++){
    data[i] = odata + i * x;
  }

  return data;
}

void  pbm_free(char **pbm, int x, int y) {
  int i;
  for (i = 0; i<y; i++)
    free(pbm[i]);
  free(pbm);
}

void   pbm_write(char **pbm, int x, int y) {
  int i, j;
  /* 最初にP1とx,yの画素数を出力 */
  printf("P1\n");
  printf("%d %d\n", x, y);
  /* 実際のデータ出力 */
  for (i = 0; i < y; i++) {
    for (j = 0; j < x; j++) {
      printf("%c ", pbm[i][j]);
    }
    printf("\n");
  }
}

char **pbm_read(int *x_sizep, int *y_sizep){

  int i, j, x_size, y_size;
  char **data;

  /* 最初にP1と書いていないものはデータ形式が違う */
  if (getchar() != 'P' || getchar() != '1'){
    fprintf(stderr, "データの形式が違います\n");
    return NULL;
  }

  /* x,yそれぞれの画素数を得る */
  scanf("%d", &x_size);
  scanf("%d", &y_size);

  data=pbm_alloc(x_size, y_size);
  
  /* 実際のデータ入力 */
  for (i = 0; i < y_size; i++){
    for (j = 0; j < x_size; j++){
      /* scanf入力データがおかしいかＥＯＦになった場合             */
      /* この際、" %c"とすることで空白、改行、タブなどは読み飛ばす */
      if(scanf(" %c", &data[i][j]) != 1){
	return NULL;
      }
      /* データが０／１じゃない場合 */
      if(data[i][j] != WHITE && data[i][j] != BLACK){
	fprintf(stderr, "データが異常でした\n");
	return NULL;
      }
    }
  }

  /* サイズの設定 */
  *x_sizep = x_size;
  *y_sizep = y_size;
  
  return data;
}



/********************************************/
/* 画像に円を描画                         */
/* pbm, x, y: 画像データの配列と大きさ      */
/* r: 円の半径　　　                        */
/* col: 線分の色(0か1)                      */
/********************************************/
void   pbm_circle(char **pbm, int x, int y, int r, char col) {

  int i;

  double rad;
  
  for(i=0;i<360;i++){

    rad = i * PI / 180.0;

    pbm[(y/2)+(int)((r*sin(rad)))][(x/2)+(int)((r*cos(rad)))]=col;


    pbm[(y/2)+(int)((r/2*sin(rad)))][(x/2)+(int)((r/2*cos(rad)))]=col;
    
  }

  pbm_write(pbm, x, y);

}
