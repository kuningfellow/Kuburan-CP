//UVA 10360 Rat Attack
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ar[1025][1025];
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int d,n,a,b,c;
        cin>>d>>n;
        for (int i=0;i<1025;i++)
        {
            for (int j=0;j<1025;j++)
            {
                ar[i][j]=0;
            }
        }
        for (int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            for (int j=-d;j<=d;j++)
            {
                for (int k=-d;k<=d;k++)
                {
                    if (a+j>=0&&a+j<1025&&b+k>=0&&b+j<1025)
                    {
                        ar[a+j][b+k]+=c;
                    }
                }
            }
        }
        int x=0,y=0;
        for (int i=0;i<1025;i++)
        {
            for (int j=0;j<1025;j++)
            {
                if (ar[i][j]>ar[x][y])
                {
                    x=i;
                    y=j;
                }
            }
        }
        printf ("%d %d %d\n",x,y,ar[x][y]);
    }
}
