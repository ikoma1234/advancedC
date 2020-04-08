#include <stdio.h>
#include <math.h>
#include "prog03_1.h"
double GetArea(Point a, Point b, Point c){
    double S,s,d1,d2,d3;
    d1 = GetDistance(a.x, a.y, b.x, b.y);
    d2 = GetDistance(b.x, b.y, c.x, c.y);
    d3 = GetDistance(c.x, c.y, a.x, a.y);
    s = (d1 + d2 + d3) / 2.0;
    S = sqrt(s*(s-d1)*(s-d2)*(s-d3));
    return S;
}
