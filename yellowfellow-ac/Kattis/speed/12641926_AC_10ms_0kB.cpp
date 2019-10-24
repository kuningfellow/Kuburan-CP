#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    double t;
    cin>>n>>t;
    int ar[n][2];
    int mini=(1<<30);
    for (int i=0;i<n;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
        mini=min(ar[i][1],mini);
    }
    double l=-1000000000;
    double r=1000000000;
    double ans;
    double rat;
    double mid;
    for (int i=0;i<1000;i++)
    {
        mid=(l+r)/2;
        ans=mid;
        rat=0;
        for (int j=0;j<n;j++)
        {
            rat+=(double)ar[j][0]/(ar[j][1]+mid);
        }
        if (mid+mini<0||rat>t)
        {
            l=mid;
        }
        else r=mid;
    }
    printf ("%.9f\n",ans);
}
