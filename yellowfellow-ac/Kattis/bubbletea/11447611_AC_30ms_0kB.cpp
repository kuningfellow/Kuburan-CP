#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&n);
    int tea[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&tea[i]);
    }
    scanf("%d",&m);
    int topping[m];
    for (int i=0;i<m;i++)
    {
        scanf("%d",&topping[i]);
    }
    vector<int>comb[n];
    int k,l;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&k);
        for (int j=0;j<k;j++)
        {
            scanf("%d",&l);
            l--;
            comb[i].push_back(l);
        }
    }
    int price=10000000;
    int te;
    int ok=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            for (int k=0;k<comb[i].size();k++)
            {
                if (comb[i][k]==j)
                {
                    ok=1;
                    break;
                }
            }
            if (ok==1)
            {
                te=tea[i]+topping[j];
                price=min(te,price);
            }
            ok=0;
        }
    }
    int monet;
    scanf("%d",&monet);
    if (monet/price>1)
        printf ("%d\n",monet/price-1);
    else printf ("0\n");
}
