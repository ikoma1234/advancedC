#include <stdio.h>
#include "prog03_1.h"
 
int main () {
    int i;
    Point v[3], w[3];
    Point v_cent, w_cent;
    double v_area, w_area;
    while(1)
    {    
        printf("Input 1st triangle: \n");
        for(i = 0; i < 3; i++)
        {
            printf("Vertex %d: ", i + 1);
            v[i] = InputShape();
        }
        //trueであればbreak;
        if(IsTriangle(v[0], v[1], v[2]) == 1)
        {
            for(i = 0; i < 3; i++) printf("\tV%d: (%lf, %lf)\n", i + 1, v[i].x, v[i].y);
            break;
        }
        else printf("These data can not form a triangle!\nAgain, ");
    }
    while(1)
    {    
        printf("Input 2nd triangle: \n");
        for(i = 0; i < 3; i++)
        {
            printf("Vertex %d: ", i + 1);
            w[i] = InputShape();
        }
        //trueであればbreak;
        if(IsTriangle(w[0], w[1], w[2]) == 1)
        {
            for(i = 0; i < 3; i++) printf("\tV%d: (%lf, %lf)\n", i + 1, w[i].x, w[i].y);
            break;
        }   
        else printf("These data can not form a triangle!\nAgain, ");
    }
    v_area = GetArea(v[0], v[1], v[2]);
    w_area = GetArea(w[0], w[1], w[2]);
    
    printf("Area of 1st one: %lf   Area of 2nd one: %lf\n", v_area, w_area);
    
    /* 面積の大きい方を表示 */
    if(v_area > w_area) printf("The 1st one is larger than the 2nd one!\n");
    else printf("The 2nd one is larger than the 1st one!\n");
    
    v_cent = GetCentroid(v[0], v[1], v[2]);
    w_cent = GetCentroid(w[0], w[1], w[2]);
    
    printf("Centroid of 1st one: (%lf, %lf)   Centroid of 2nd one: (%lf, %lf))\n", v_cent.x, v_cent.y, w_cent.x, w_cent.y);
    return 0;
}
