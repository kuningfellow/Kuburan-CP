//UVA 481 What Goes Up
//LIS using vector
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int>ar[50000];
int ans;
void serc(int l, int r, int n)
{
    if (l<=r)
    {
        int mid=(l+r)/2;
        if (ar[mid][ar[mid].size()-1]<n)
        {
            ans=mid;
        }
        if (ar[mid][ar[mid].size()-1]>=n)
        {
            serc(l,mid-1,n);
        }
        if (ar[mid][ar[mid].size()-1]<n)
        {
            serc(mid+1,r,n);
        }
    }
}
int main()
{
    int siz=0;
    ar[0].push_back(-(1<<30));
    int done=0;
    int n;
    int fir=1;
    while (scanf("%d",&n)!=EOF)
    {
        serc(0,siz,n);
        ar[ans+1].clear();
        for (int i=0;i<ar[ans].size();i++)
        {
            ar[ans+1].push_back(ar[ans][i]);
        }
        ar[ans+1].push_back(n);
        if (ans+1>siz)siz=ans+1;
    }
    printf ("%d\n-\n",siz);
    for (int i=1;i<ar[siz].size();i++)
    {
        printf ("%d\n",ar[siz][i]);
    }
}
