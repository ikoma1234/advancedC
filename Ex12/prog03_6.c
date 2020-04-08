#include "prog03_1.h"
Point GetCentroid(Point a,Point b, Point c){
  Point Cog;
  Cog.x = (a.x + b.x + c.x) / 3.0;
  Cog.y = (a.y + b.y + c.y) / 3.0;
  return Cog;
}
