#include "prog03_1.h"
#include <math.h>
#include <stdio.h>

int IsTriangle(Point a, Point b, Point c){

    double d1, d2, d3;
  
    d1 = GetDistance(a.x, a.y, b.x, b.y);
    d2 = GetDistance(b.x, b.y, c.x, c.y);
    d3 = GetDistance(c.x, c.y, a.x, a.y);
  
    if(d1 + d2 > d3 && d2+d3 > d1 && d3+d1 > d2) return 1;
    else return 0;
}

double GetDistance(double x1, double y1, double x2, double y2){
    double tmpx, tmpy;
    tmpx = x2 - x1;
    tmpy = y2 - y1;
    return sqrt(tmpx*tmpx + tmpy*tmpy);
}
