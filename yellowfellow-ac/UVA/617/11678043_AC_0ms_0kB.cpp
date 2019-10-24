//UVA 617 Nonstop Travel
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int kasus=1;
    int n;
    while (1<2)
    {
        cin>>n;
        if (n==-1)break;
        vector<double>p;
        vector<int>t[3];
        int  b,c,d;
        double a;
        for (int i=0;i<n;i++)
        {
            scanf("%lf%d%d%d",&a,&b,&c,&d);
            p.push_back(a);
            t[0].push_back(b);
            t[1].push_back(c);
            t[2].push_back(d);
        }
        vector<int>good;
        for (int i=30;i<=60;i++)
        {
            int co=0;
            for (int j=0;j<p.size();j++)
            {
                int tem=3600*p[j]/i;
                tem%=(t[0][j]+t[1][j]+t[2][j]);
                if (tem<t[0][j]+t[1][j])
                    co++;
            }
            if (co==p.size())
            {
                good.push_back(i);
            }
        }
        printf ("Case %d: ",kasus);
        kasus++;
        for (int i=0;i<good.size();i++)
        {
            int j=i;
            while (j+1<good.size()&&good[j]+1==good[j+1])
            {
                j++;
            }
            if (good[j]==good[i])
                printf ("%d",good[i]);
            else
            {
                printf ("%d-%d",good[i],good[j]);
                i=j;
            }
            if (i<good.size()-1)
            {
                printf (", ");
            }
        }
        if (good.size()==0)printf ("No acceptable speeds.");
        printf ("\n");
    }
}
