#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * MAXDATA:最大データ数
 * LENIP  :IPアドレスの最長文字数+1
 * LENHOST:最長文字数+1
 */
#define MAXDATA 1024
#define LENIP   16
#define LENHOST 256

int main(){
  int i;
  int ndata;
  FILE *fp;
  char ipadr[MAXDATA][LENIP];
  char host [MAXDATA][LENHOST];
  char query[LENHOST];
  /* その他必要な変数を定義して良い */

    /*** データの読み出し処理 ***/
    /* ファイルのオープン */
    fp = fopen("stdhosts.txt", "r");
    if (fp == NULL) {
      printf("Cannot open file!\n");
      exit(1);
    }
    /* データの読み出し */
    for( i=0 ; i < MAXDATA ; i++ ){
      /* ２項目読めなければループを抜ける */
      if (fscanf(fp,"%s %s",
		 ipadr[i],host[i]) != 2) break;
    }
    ndata=i;

    /*** 問合せの処理 ***/
    while(1){
         
      /* 文字列の配列の使用方法に注意      *
       * host[xxx]でxxx番目の文字列を示す */
      if(strcmp(host[i],query)==1) printf("");
		   
	}

    fclose(fp);
    return 0;
}
