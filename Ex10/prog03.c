#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;        /* アリの位置（横） */
  int y;        /* アリの位置（縦） */
  char dr;      /* 'R':右向き  'D':下向き */
  int in;       /* 1:アリは盤上にいる 0:既に盤外に出ている */
}AntPos;

int main(int argc, char *argv[]){
  int w, h, n;  /* 幅、高さ、初期状態でのアリの数 */
  int t=1;      /* 時間ステップのカウンタ */
  int i, j, k, num;
  AntPos *ant;
  FILE *ifile;

  if (argc < 2) {
    printf( "error: input file name is required!\n");
    exit(1);
  }
  /* ファイルオープン */
  if((ifile=fopen(argv[1],"r"))==NULL){
    printf("Cannnot open the file.\n");
    exit(8);
  }

  /* ファイルの1行目から盤の幅w、高さh、アリの数nを読み込む */
  fscanf(ifile,"%d%d%d",&w,&h,&n);
 
  /* アリの情報を収めておく構造体配列を動的に確保 */
  ant = (AntPos *)malloc(n * sizeof(AntPos));
 
  /* ファイルから各アリの位置と向きを読み込む。なお、文字型を読む時は
     " %c"のように%c手前にスペースを入れると、R/D手前のスペースを読み飛ばせる。
     読み込めたら、確認のため読んだ情報を一度出力しておこう */
  for(i=1;i<n+1;i++){
    fscanf(ifile,"%d%d %c",&ant[i].x,&ant[i].y,&ant[i].dr);
    printf("%d %d %c\n",ant[i].x,ant[i].y,ant[i].dr);
  }  

  /* 1ステップごとのループ。盤上にいるアリの数が0になったら終了 */
    /* 時間の更新、アリの座標の更新、アリが盤の外に出たかどうかのチェックと表示、

       2匹のアリが同じマスにいるかどうかのチェックと（必要なら）向きの更新 */

  num=n;

  for(j=0;num>0;j++){
    for(i=1;i<n+1;i++){
      if((ant[i].x<=w)&&(ant[i].y<=h)){
	if(ant[i].dr=='R'){
	  ant[i].x++;
	  if(ant[i].x>w){
	    printf("Step %d: Ant No.%d has gone out to (%d,%d).\n", t, i, ant[i].x, ant[i].y);
	    num--;	    
	  }	  
	}
      	else if(ant[i].dr=='D'){
	  ant[i].y++;
	  if(ant[i].y>h){
	    printf("Step %d: Ant No.%d has gone out to (%d,%d).\n", t, i, ant[i].x, ant[i].y);
	    num--;	    
	  }
	}	
      }
    }
    for(i=1;i<n+1;i++){

      for(k=i+1;k<n+1;k++){

	if((ant[i].x==ant[k].x)&&(ant[i].y==ant[k].y)){
	  if((ant[i].x%2==0)&&(ant[i].y%2==0)){

	    if(ant[i].dr=='R'){
	      ant[i].dr='D';
	    }
	    else if(ant[i].dr=='D'){
	      ant[i].dr='R';
	    }
	    
	    if(ant[k].dr=='R'){
	      ant[k].dr='D';
	    }
	    else if(ant[k].dr=='D'){
	      ant[k].dr='R';
	    }
	  }
	  else if((ant[i].x%2==1)&&(ant[i].y%2==1)){

	    if(ant[i].dr=='R'){
	      ant[i].dr='D';
	    }
	    else if(ant[i].dr=='D'){
	      ant[i].dr='R';
	    }
	    
	    if(ant[k].dr=='R'){
	      ant[k].dr='D';
	    }
	    else if(ant[k].dr=='D'){
	      ant[k].dr='R';
	    }
	      
	  }

	}
      }

    }

    t++;
  }

  
  return 0;
}
