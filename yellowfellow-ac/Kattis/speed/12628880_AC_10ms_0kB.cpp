#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int ar[n][2];
    int low=(1<<30);
    for (int i=0;i<n;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
        if (ar[i][1]<low)low=ar[i][1];
    }
    double l,r,mid,ans;
    l=-1000000000;
    double rat;
    double comp=(double)d;
    r=1000000000;
    for (int i=0;i<1000;i++)
    {
        mid=(l+r)/2;
        ans=mid;
        rat=0;
        for (int i=0;i<n;i++)
        {
            rat+=(double)ar[i][0]/(ar[i][1]+(double)mid);
        }
        if (mid+low<0||rat>comp)
        {
            l=mid;
        }
        else r=mid;
    }
    printf ("%.9f\n",ans);
}
