//UVA 10048 Audiophobia
//floyd warshall
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int con[105][105];
int n;
int main()
{
    int kas=1;
    while (1<2)
    {
        int e,q;
        cin>>n>>e>>q;
        if (n==0&&e==0&&q==0)break;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                con[i][j]=-1;
            }
        }
        int a,b,c;
        for (int i=0;i<e;i++)
        {
            cin>>a>>b>>c;
            con[a-1][b-1]=c;
            con[b-1][a-1]=c;
        }
        for (int k=0;k<n;k++)
        {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (con[i][k]!=-1&&con[k][j]!=-1)
                    {
                        c=max(con[i][k],con[k][j]);
                    }
                    else continue;
                    if (con[i][j]==-1)
                    {
                        con[i][j]=c;
                    }
                    else
                    {
                        con[i][j]=min(con[i][j],c);
                    }
                }
            }
        }
        if (kas>1)printf ("\n");
        printf ("Case #%d\n",kas++);
        for (int i=0;i<q;i++)
        {
            cin>>a>>b;
            c=con[a-1][b-1];
            if (c==-1)printf ("no path\n");
            else printf ("%d\n",c);
        }
    }
}
