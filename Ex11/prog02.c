#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_1(double, Point, Point);
void  rotate_2(double, Point, Point *);
Point rotate_3(double, Point *);
void rotate_4(double, Point *);

int main()
{
  double rad, deg;
  Point pc = {2.0, 3.0}, p = {4.0, 6.0}, p1,p2,p3;
  Point p3h[2],p4[2];

  printf("回転角度[度]をいれて下さい\n");
  scanf("%lf", &deg);
  rad=deg*M_PI/180;
  printf("Theta %f [deg](%f [rad])\n",deg,rad);
  printf("pc: %f %f\n",pc.x,pc.y);
  printf("p : %f %f\n",p.x,p.y);
  
/*
 * ここに関数呼び出し及び関連するコードを書く
 */
  p3h[0]=pc;
  p3h[1]=p;
  
  p3=rotate_3(rad,p3h);

  p4[0]=pc;
  p4[1]=p;
  
  rotate_4(rad,p4);
  
  printf("rotate_3: %f %f\n",p3.x,p3.y);
  printf("rotate_4: %f %f\n",p4[1].x,p4[1].y);

  return 0;
}

Point rotate_3(double theta, Point *p){
  
  Point temp;
  
  temp.x=(p[1].x-p[0].x)*cos(theta)+(p[1].y-p[0].y)*(-sin(theta));
  temp.y=(p[1].x-p[0].x)*sin(theta)+(p[1].y-p[0].y)*cos(theta);

  temp.x+=p[0].x;
  temp.y+=p[0].y;
  
  return temp;
  

}

void rotate_4(double theta, Point *p){

  Point temp;

  temp=p[1];
  
  p[1].x=(temp.x-p[0].x)*cos(theta)+(temp.y-p[0].y)*(-sin(theta));
  p[1].y=(temp.x-p[0].x)*sin(theta)+(temp.y-p[0].y)*cos(theta);

  p[1].x+=p[0].x;
  p[1].y+=p[0].y;
  }
