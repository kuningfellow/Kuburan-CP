#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[10000];
int lis[5000005];
int siz;
void sieve()
{
    for (int i=2;i<10000;i++)
    {
        if (isprime[i]==0)
        {
            lis[siz++]=i;
            for (int j=i*2;j<10000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
bool seg[1000005];
int done;
void segify(int l)
{
    int sta;
    for (int i=0;i<siz;i++)
    {
        if (lis[i]*lis[i]>l+1000000)break;
        sta=(l/lis[i]*lis[i]+lis[i]*(l%lis[i]>0))-l;
        for (int j=sta;j<1000000;j+=lis[i])
        {
            seg[j]=1;
        }
    }
    for (int i=0;i<1000000;i++)
    {
        if (seg[i]==0)
        {
            lis[siz++]=i+l;
            if (siz>5000000)
            {
                done=1;
                break;
            }
        }
        seg[i]=0;
    }
}
int main()
{
    sieve();
    for (int i=10000;i<87000000;i+=1000000)
    {
        segify(i);
        if (done==1)break;
    }
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        printf ("%d\n",lis[n-1]);
    }
}
