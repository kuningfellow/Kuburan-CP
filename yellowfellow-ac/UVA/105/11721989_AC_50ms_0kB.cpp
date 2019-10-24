//UVA 105 The Skyline Problem
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int>build[3];
    int a,b,c;
    int l=(1<<31)-1;
    int r=0;
    while (scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        build[0].push_back(a);
        build[1].push_back(b);
        build[2].push_back(c);
        if (c>r)r=c;
        if (a<l)l=a;
    }
    int h=0;
    int ph=0;
    for (int j=l;j<=r;j++)
    {
        h=0;
        for (int i=0;i<build[0].size();i++)
        {
            if (j>=build[0][i]&&j<build[2][i])
            {
                if (build[1][i]>h)
                {
                    h=build[1][i];
                }
            }
        }
        if (ph!=h)
        {
            if (j==r)
                printf ("%d %d\n",j,h);
            else printf ("%d %d ",j,h);
        }
        ph=h;
    }
}
