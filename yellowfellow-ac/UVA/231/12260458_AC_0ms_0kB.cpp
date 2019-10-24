//UVA 231 Testing the CATCHER
//LIS binary search
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ar[50000];
int ans;
void serc(int l, int r, int n)
{
    if (l<=r)
    {
        int mid=(l+r)/2;
        if (ar[mid]>n)
        {
            ans=mid;
        }
        if (ar[mid]<n)
        {
            serc(l,mid-1,n);
        }
        if (ar[mid]>=n)
        {
            serc(mid+1,r,n);
        }
    }
}
int main()
{
    int kas=1;
    while (1<2)
    {
        int siz=0;
        ar[0]=(1<<30);
        int done=0;
        int n;
        int fir=1;
        while (1<2)
        {
            cin>>n;
            if (n==-1)
            {
                if (fir==1)
                    done=1;
                break;
            }
            fir=0;
            serc(0,siz,n);
            ar[ans+1]=n;
            if (ans+1>siz)siz=ans+1;
        }
        if (done==1)break;
        if (kas>1)printf ("\n");
        printf ("Test #%d:\n  maximum possible interceptions: %d\n",kas++,siz);
    }
}
