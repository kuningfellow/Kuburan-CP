#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
int n;
int squr(int a)
{
    return a*a;
}
vector<int>pos[2];

pair<double,int> to[10][1024];

double sear(int k,int mask)
{
    if (mask==(1<<n)-1)
    {
        return 0;
    }
    int i,q;
    double j=10000000,d,e;
    for (i=1;i<n;i++)
    {
        if ((mask&(1<<i))>0)continue;
        d=sear(i,mask|(1<<i));
        if (k==0)
            e=d;
        else
            e=16+sqrt(squr(pos[0][k]-pos[0][i])+squr(pos[1][k]-pos[1][i]))+d;
        if (j>e)
        {
            j=e;
            to[k][mask]=pair<double,int>(e,i);
        }
    }
    return j;
}
int main()
{
    int kasus=1;
    while (1)
    {
        scanf("%d",&n);
        if (n==0)break;
        int i;
        int a,b;
        pos[0].push_back(-1);
        pos[1].push_back(-1);
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            pos[0].push_back(a);
            pos[1].push_back(b);
        }
        n++;
        double cost=sear(0,1);
        int w=to[0][1].second,e=1;
        e=(e|(1<<w));
        printf ("**********************************************************\n");
        printf ("Network #%d\n",kasus);
        kasus++;
        for (int j=0;j<n-2;j++)
        {
            printf ("Cable requirement to connect ");
            printf ("(%d,%d) to (%d,%d) is %.2f feet.\n",pos[0][w],pos[1][w],pos[0][(to[w][e].second)],pos[1][(to[w][e].second)],to[w][e].first-to[to[w][e].second][e|(1<<to[w][e].second)].first);
            w=to[w][e].second;
            e=(e|(1<<w));
        }
        printf ("Number of feet of cable required is %.2f.\n",cost);
        pos[0].clear();
        pos[1].clear();
        for (i=0;i<10;i++)
        {
            for (int j=0;j<1024;j++)
            {
                to[i][j]=make_pair(0,0);
            }
        }
    }
    return 0;
}