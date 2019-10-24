#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char ram[n][m+1];
    string rem[m];
    for (int i=0;i<n;i++)
    {
        scanf("%s",ram[i]);
    }
    int l=0,r=n-1,mid,ans,ye;
    map<string,int>kep;
    while (l<=r)
    {
        mid=(l+r)/2;
        ye=0;
        for (int i=0;i<m;i++)
        {
            rem[i].clear();
            for (int j=0;j<=mid;j++)
            {
                rem[i]+=ram[n-1-j][i];
            }
            if (kep[rem[i]]==1)
                ye=1;
            kep[rem[i]]=1;
        }
        if (ye==0)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf ("%d\n",n-ans-1);
}
