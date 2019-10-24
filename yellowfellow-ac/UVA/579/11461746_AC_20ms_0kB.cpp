#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int h,m;
    while (1<2)
    {
        scanf("%d:%d",&h,&m);
        if (h==0&&m==0)break;
        double H,M;
        H=(double)h/12*360;
        H+=(double)m/2;
        M=m*6;
        double deg=H-M;
        if (deg<0)
        {
            deg=-deg;
        }
        if (deg>180)
        {
            deg=360-deg;
        }
        printf ("%.3f\n",deg);
    }
}
