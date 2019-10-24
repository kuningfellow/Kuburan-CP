//UVA 10583 Ubiquitous Religions
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
    int kas=1;
    while (1<2)
    {
        int n,m,co=0;
        cin>>n>>m;
        if (n==0&&m==0)break;
        for (int i=1;i<n+1;i++)
            kid[i]=i;
        int a,b;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            update(a,b);
        }
        for (int i=1;i<n+1;i++)
        {
            if (kid[i]==i)co++;
        }
        printf ("Case %d: %d\n",kas++,co);
    }

}
