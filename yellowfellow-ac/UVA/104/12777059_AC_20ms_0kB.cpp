//UVA 104 Arbitrage
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
double mat[22][22];
double res[22][22];
int bac[22][22][22];
double temp[22][22];
int n;
void mul(int step)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            temp[i][j]=0;
            for (int k=0;k<n;k++)
            {
                if (res[i][k]*mat[k][j]>temp[i][j])
                {
                    temp[i][j]=res[i][k]*mat[k][j];
                    bac[step][i][j]=k;
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            res[i][j]=temp[i][j];
        }
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i==j)
                {
                    mat[i][j]=0;
                    res[i][j]=0;
                    continue;
                }
                scanf("%lf",&mat[i][j]);
                res[i][j]=mat[i][j];
            }
        }
        int st=0;
        int co=n;
        int x=-1,y;
        while (co>0)
        {
            co--;
            mul(st++);
            for (int i=0;i<n;i++)
            {
                if (res[i][i]>1.01)
                {
                    co=-1;
                    x=i;
                    y=i;
                    break;
                }
            }
        }
        if (x==-1)
        {
            printf ("no arbitrage sequence exists\n");
        }
        else
        {
            vector<int>lis;
            lis.push_back(x+1);
            while (st--)
            {
                lis.push_back(bac[st][x][y]+1);
                y=bac[st][x][y];
            }
            lis.push_back(x+1);
            for (int i=lis.size()-1;i>=0;i--)
            {
                printf ("%d",lis[i]);
                if (i>0)printf (" ");
            }
            printf ("\n");
        }
    }
}