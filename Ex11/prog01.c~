#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_1(double, Point, Point);
void  rotate_2(double, Point, Point *);

int main()
{
  double rad, deg;
  Point pc = {2.0, 3.0}, p = {4.0, 6.0}, p1,p2;

  printf("回転角度[度]をいれて下さい\n");
  scanf("%lf", &deg);
  rad=deg*M_PI/180;
  printf("Theta %f [deg](%f [rad])\n",deg,rad);
  printf("pc: %f %f\n",pc.x,pc.y);
  printf("p : %f %f\n",p.x,p.y);
  
/*
 * ここに関数呼び出し及び関連するコードを書く
 */
  p1=rotate_1(rad,pc,p);

  p2=p;
  
  rotate_2(rad,pc,&p2);
  
  printf("rotate_1: %f %f\n",p1.x,p1.y);
  printf("rotate_2: %f %f\n",p2.x,p2.y);

  return 0;
}

Point rotate_1(double theta, Point center, Point p)
{
/*
 * ここに関数の中身を書く
 */

  Point temp;
  
  temp.x=(p.x-center.x)*cos(theta)+(p.y-center.y)*(-sin(theta));
  temp.y=(p.x-center.x)*sin(theta)+(p.y-center.y)*cos(theta);

  temp.x+=center.x;
  temp.y+=center.y;
  
  return temp;
}

void rotate_2(double theta, Point center, Point *p)
{
/*
 * ここに関数の中身を書く
 */
  Point temp;

  temp=*p;
  
  p->x=(temp.x-center.x)*cos(theta)+(temp.y-center.y)*(-sin(theta));
  p->y=(temp.x-center.x)*sin(theta)+(temp.y-center.y)*cos(theta);

  p->x+=center.x;
  p->y+=center.y;
}
