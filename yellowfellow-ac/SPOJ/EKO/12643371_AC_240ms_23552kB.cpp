#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    long long int m;
    scanf("%d%lld",&n,&m);
    long long int ar[n];
    int up=0;
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&ar[i]);
        if (ar[i]>up)up=ar[i];
    }
    long long int l=0;
    long long int r=up;
    long long int mid;
    long long int ans;
    long long int res;
    while (l<=r)
    {
        mid=(l+r)/2;
        res=0;
        for (int i=0;i<n;i++)
        {
            res+=max(ar[i]-mid,0ll);
        }
        if (res>=m)
        {
            ans=mid;
        }
        if (res<m)
        {
            r=mid-1;
        }
        else if (res>=m)
        {
            l=mid+1;
        }
    }
    printf ("%lld\n",ans);
}
