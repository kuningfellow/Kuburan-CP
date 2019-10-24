#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,c;
        cin>>n>>c;
        int ar[n];
        int l=0;
        int r=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            r=max(r,ar[i]);
        }
        sort(ar,ar+n);
        int mid,ans;
        int pick;
        int co=0;
        int i;
        while (l<=r)
        {
            mid=(l+r)/2;
            pick=0;
            co=1;
            i=1;
            while (i<n&&co<c)
            {
                if (ar[i]-ar[pick]>=mid)
                {
                    co++;
                    pick=i;
                }
                i++;
            }
            if (co==c)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        printf ("%d\n",ans);
    }
}