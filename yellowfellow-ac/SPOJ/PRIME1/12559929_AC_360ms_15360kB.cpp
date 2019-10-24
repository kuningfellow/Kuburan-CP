#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[100005];
vector<int>lis;
void sieve()
{
    int i;
    for (i=2;i*i<100005;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<100005;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
    for (;i<100005;i++)
    {
        if (isprime[i]==0)
            lis.push_back(i);
    }
}
int main()
{
    sieve();
    int tc,fir=0;
    cin>>tc;
    while (tc--)
    {
        long long int a,b;
        cin>>a>>b;
        if (fir==1)
            printf ("\n");
        fir=1;
        for (long long int i=a;i<=b;i++)
        {
            if (i<100005)
            {
                if (isprime[i]==0&&i!=1)
                    printf ("%lld\n",i);
            }
            else
            {
                int yes=1;
                for (int j=0;j<lis.size();j++)
                {
                    if (lis[j]*lis[j]>i)break;
                    if (i%lis[j]==0)
                    {
                        yes=0;
                        break;
                    }
                }
                if (yes==1)printf ("%lld\n",i);
            }
        }
    }
}
