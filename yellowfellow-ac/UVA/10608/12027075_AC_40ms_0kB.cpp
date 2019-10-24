//UVA 10608 Friends
#include <stdio.h>
#include <iostream>
using namespace std;
int kid[50001];
int finpar(int x)
{
    if (x==kid[x])return x;
    else if (x!=kid[x])return kid[x]=finpar(kid[x]);
}
int update(int x, int y)
{
    int a=finpar(x);
    int b=finpar(y);
    if (a!=b)
    {
        kid[a]=b;
        finpar(x);
    }
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,m,co=0;
        cin>>n>>m;
        if (n==0&&m==0)break;
        int coun[n+1];
        for (int i=1;i<n+1;i++)
        {
            coun[i]=0;
            kid[i]=i;
        }
        int a,b;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            update(a,b);
        }
        for (int i=1;i<n+1;i++)
        {
            finpar(i);
        }
        int maxi=0;
        for (int i=1;i<n+1;i++)
        {
            coun[kid[i]]++;
            if (coun[kid[i]]>maxi)maxi=coun[kid[i]];
        }
        printf ("%d\n",maxi);
    }
}
