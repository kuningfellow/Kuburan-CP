#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int ar[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&ar[i]);
    }
    sort(ar,ar+n);
    int l,r,ans,mid;
    long long int a;
    for (int i=0;i<m;i++)
    {
        scanf("%lld",&a);
        l=0;
        r=n-1;
        ans=-1;
        while (l<=r)
        {
            mid=(l+r)/2;
            if (ar[mid]==a)
            {
                ans=mid;
            }
            if(ar[mid]>=a)
            {
                r=mid-1;
            }
            else if (ar[mid]<a)
            {
                l=mid+1;
            }
        }
        printf ("%d\n",ans);
        if (i<m-1)printf ("\n");
    }
}
