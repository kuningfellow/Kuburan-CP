//UVA 10125 Sumset
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int ar[1005];
map<int,vector<pair<int,int> > >rem;
int main()
{
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                rem[ar[i]+ar[j]].push_back(pair<int,int>(i,j));
            }
        }
        int tem=-(1<<30);
        int foun=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i==j)continue;
                int x=ar[j]-ar[i];
                if (rem[x].size()>0)
                {
                    int l=rem[x].size();
                    for (int k=0;k<l;k++)
                    {
                        if (!(i==rem[x][k].first||j==rem[x][k].first||i==rem[x][k].second||j==rem[x][k].second))
                        {
                            foun=1;
                            tem=max(tem,ar[j]);
                            break;
                        }
                    }
                }
            }
        }
        if (foun==0)printf ("no solution\n");
        else printf ("%d\n",tem);
        rem.clear();
    }
}
