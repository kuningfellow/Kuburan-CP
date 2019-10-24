//UVA 1197 The Suspects
#include <stdio.h>
int par[30005];
int siz[30005];
int finpar(int x)
{
    if (par[x]==x)return x;
    return par[x]=finpar(par[x]);
}
int update(int x, int y)
{
    int X=finpar(x);
    int Y=finpar(y);
    if (X!=Y)
    {
        siz[X]+=siz[Y];
        siz[Y]=0;
        par[Y]=X;
    }
}
int main()
{
    while (1<2)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        for (int i=0;i<n;i++)
        {
            par[i]=i;
            siz[i]=1;
        }
        int a,b,c;
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            for (int j=0;j<a-1;j++)
            {
                scanf("%d",&c);
                update(b,c);
            }
        }
        printf ("%d\n",siz[finpar(0)]);
    }
}
