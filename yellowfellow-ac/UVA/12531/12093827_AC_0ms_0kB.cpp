//UVA 12531 Hours and Minutes
#include <stdio.h>
#include <vector>
using namespace std;
int lis[361];
int main()
{
    int d;
    for (int i=0;i<12;i++)
    {
        for (int j=0;j<60;j++)
        {
            d=((i*30+j/12*6)-j*6+360)%360;
            lis[min(d,(360-d))]=1;
        }
    }
    while (scanf("%d",&d)!=EOF)
    {
        if (lis[d]==1)printf ("Y\n");
        else printf ("N\n");
    }
}
