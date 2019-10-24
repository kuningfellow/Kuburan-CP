#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    int minu=m*6;
    double hou=h*30+(double)m/2;
    while (hou>=360)hou-=360;
        printf ("%f %d\n",hou,minu);
}
