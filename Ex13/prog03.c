#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'

char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
char **pbm_read(int *, int *);
void   pbm_write(char **, int, int);
char **pbm_erode(char **pbm, int x, int y);  /* エロージョンを行う関数 */
char **pbm_dilate(char **pbm, int x, int y); /* ダイレーションを行う関数 */

char *odata;

int main(){
  char **pbm1, **pbm2;
  int ix,iy;

  pbm1 = pbm_read(&ix,&iy);
  if(pbm1==NULL){
    fprintf(stderr,"Invlid image format.");
    exit(1);
  }

#ifdef ERODE
  pbm2=pbm_erode(pbm1,ix,iy);
 
#elif DILATE
  pbm2=pbm_dilate(pbm1,ix,iy);
 
#else
  pbm2=pbm1;

#endif

  /* 画像を書きだす */
  pbm_write(pbm2,ix,iy);
  /* 画像領域の解放 */
  pbm_free(pbm2,ix,iy);
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

char **pbm_erode(char **pbm, int x, int y){

  int i,j;
  char **pbm2;
 
  pbm2=pbm_alloc(x, y);
  
  for(i=0;i<y;i++){
    for (j = 0; j < x; j++){ 
      pbm2[i][j]=pbm[i][j];
    }
  }

   for (i = 1; i < y-1; i++) {
    for (j = 1; j < x-1; j++) {

      if (pbm[i][j] != '1'){
	pbm2[i][j] = '0';
      }
      if (pbm[i+1][j] != '1'){
	pbm2[i][j] = '0';
      }
      if (pbm[i][j+1] != '1'){
	pbm2[i][j] = '0';
      }
      if (pbm[i-1][j] != '1'){
	pbm2[i][j] = '0';
      }
      if (pbm[i][j-1] != '1') {
	pbm2[i][j] = '0';
      }
     
    }
  }   

  return pbm2;
}
  
char **pbm_dilate(char **pbm, int x, int y){

  int i,j;
  char **pbm2;

  pbm2=pbm_alloc(x, y);

  for(i=0;i<y;i++){
    for (j = 0; j < x; j++){ 
      pbm2[i][j]=pbm[i][j];
    }
  }
  
  for (i = 1; i < y-1; i++) {
    for (j = 1; j < x-1; j++) {

      if (pbm[i][j] != '0'){
	pbm2[i][j] = '1';
      }
      if (pbm[i+1][j] != '0'){
	pbm2[i][j] = '1';
      }
      if (pbm[i][j+1] != '0'){
	pbm2[i][j] = '1';
      }
      if (pbm[i-1][j] != '0'){
	pbm2[i][j] = '1';
      }
      if (pbm[i][j-1] != '0') {
	pbm2[i][j] = '1';
      }
     
    }
  }

   
  return pbm2;
}
