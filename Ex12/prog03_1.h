typedef struct
{
    double x, y;
} Point;

Point InputShape(void);

int isTriangle(Point, Point, Point);

double GetArea(Point, Point, Point);

Point GetCentroid(Point, Point, Point);

double GetDistance(double, double, double, double );
