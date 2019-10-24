#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        double h=((4*x+4*y)+sqrt((4*x+4*y)*(4*x+4*y)-4*(x*y*12)))/(2*12);
        double h2=((4*x+4*y)-sqrt((4*x+4*y)*(4*x+4*y)-4*(x*y*12)))/(2*12);
        double vol1=(x-2*h)*(y-2*h)*h;
        double vol2=(x-2*h2)*(y-2*h2)*h2;
        printf ("%.11f\n",max(vol1,vol2));
    }
}
