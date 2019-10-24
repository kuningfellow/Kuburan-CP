//UVA 1112 Mice and Maze
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,e,t,m;
        cin>>n>>e>>t>>m;
        int tim[n][n];
        int con[n][n];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                tim[i][j]=(1<<29)-1;
                con[i][j]=-1;
            }
        }
        int a,b,c;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            con[a-1][b-1]=c;
        }
        for (int k=0;k<n;k++)
        {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (con[i][j]!=-1)
                    {
                        tim[i][j]=min(tim[i][j],con[i][j]);
                    }
                    if (con[i][k]!=-1&&con[k][j]!=-1)
                    {
                        tim[i][j]=min(tim[i][j],con[i][k]+con[k][j]);
                    }
                    tim[i][j]=min(tim[i][j],tim[i][k]+tim[k][j]);
                }
            }
        }
        int mau5=0;
        for (int i=0;i<n;i++)
        {
            if (tim[i][e-1]<=t)mau5++;
            else if (i==e-1)mau5++;
        }
        printf ("%d\n",mau5);
        if (tc>0)printf ("\n");
    }
}
