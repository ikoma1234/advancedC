#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} XY; /* 平面上の点 */

typedef struct {
  XY center;
  XY p;
} CIRCLE; /* centerを中心点、pを円周上の点とする円 */

CIRCLE input1(void);   /* データを読み込んだ構造体を戻す */
void input2(CIRCLE *);/* 構造体のポインタを渡し、そこにデータを読み込む */

int main(){

  XY xy, ab;
  CIRCLE circle, circlek; /* circlek=circlekansuu */
  double r;
  
  printf("データを入力して下さい（構造体を返す関数）：");

  circlek=input1();

  r=sqrt((pow(circlek.center.x-circlek.p.x, 2)+pow(circlek.center.y-circlek.p.y, 2)));
  
  printf("input1 : r, length, area : %f, %f, %f\n", r, r*2*M_PI, pow(r, 2)*M_PI);

  printf("データを入力して下さい（構造体ポインタを使う関数）：");
  
  scanf("%lf%lf%lf%lf", &circle.center.x, &circle.center.y, &circle.p.x, &circle.p.y);
 
  input2(&circle);

  return 0;
}

CIRCLE input1(){

  XY xy, ab;
  CIRCLE circle;

  scanf("%lf%lf%lf%lf", &circle.center.x, &circle.center.y, &circle.p.x, &circle.p.y);
  
  return circle; 
}

void input2(CIRCLE *circle){


  double r;
  r=sqrt((pow(circle->center.x-circle->p.x, 2)+pow(circle->center.y-circle->p.y, 2)));
  
  printf("input1 : r, length, area : %f, %f, %f\n", r, r*2*M_PI, pow(r, 2)*M_PI);
}

  
