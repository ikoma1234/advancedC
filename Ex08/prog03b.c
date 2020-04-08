#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000
typedef struct {
  int data[N];    /* N個の要素を持つ配列 */
  int maxdata;    /* データの最大値         */
  int mindata;    /* データの最小値         */
  double avedata; /* データの平均値         */
} My_Array;

void FindMember1(My_Array *);
My_Array FindMember2(My_Array);

int main(){
/* 以下の構造体変数の宣言はmain()関数の中に書くこと */
  My_Array A;
  int i;
  double keika;
  time_t start, end;

  srand((unsigned int)time(NULL));

  for(i=0; i<999; i++){
    
  A.data[i]=rand()%1000;

  }
  start=clock();
  for(i=0;i<N;i++) FindMember1(&A);
  end=clock();
  keika=(end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by address    :%f sec\n", keika);
  
  start=clock();
  for(i=0;i<N;i++) FindMember2(A);
  end=clock();
  keika=(end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by value      :%f sec\n", keika);
  
  return 0;  
}

void FindMember1(My_Array *A){
  
  int i, saidai, saisyou;
  double heikin;

  A->avedata=0;
  for(i=0; i<999; i++){
    A->avedata+=A->data[i];
  }
  A->avedata=A->avedata/i;

  A->maxdata=A->data[i];
  for(i=0; i<998; i++){ 
    if(A->data[i]<A->data[i+1]) A->maxdata=A->data[i+1];
  }

  A->mindata=A->data[i];
  for(i=0; i<998; i++){ 
    if(A->data[i]>A->data[i+1]) A->mindata=A->data[i+1];
  }
}

My_Array FindMember2(My_Array A){
  
  int i, saidai, saisyou;
  double heikin;

  A.avedata=0;
  for(i=0; i<999; i++){
    A.avedata+=A.data[i];
  }
  A.avedata=A.avedata/i;

  A.maxdata=A.data[i];
  for(i=0; i<998; i++){ 
    if(A.data[i]<A.data[i+1]) A.maxdata=A.data[i+1];
  }

  A.mindata=A.data[i];
  for(i=0; i<998; i++){ 
    if(A.data[i]>A.data[i+1]) A.mindata=A.data[i+1];
  }
  return A;
}

  

  
    

  
  
