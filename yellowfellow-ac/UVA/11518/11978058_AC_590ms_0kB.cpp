//UVA 11518 Dominos 2
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int ar[10001];
int con[10001][10001];
int n;
void pee(int a)
{
    ar[a]=1;
    for (int i=0;i<n;i++)
    {
        if (con[a][i]==1&&ar[i]==0)
        {
            pee(i);
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int m,l,a,b;
        cin>>n>>m>>l;
        n++;
        for (int i=0;i<n;i++)
        {
            ar[i]=0;
            for (int j=0;j<n;j++)
            {
                con[i][j]=0;
            }
        }
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            con[a][b]=1;
        }
        for (int i=0;i<l;i++)
        {
            cin>>a;
            pee(a);
        }
        int co=0;
        for (int i=0;i<n;i++)
        {
            co+=ar[i];
        }
        printf ("%d\n",co);
    }
}
