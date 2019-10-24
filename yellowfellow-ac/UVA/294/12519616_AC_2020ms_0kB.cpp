#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[100005];
void sieve()
{
    for (int i=2;i*i<=100005;i++)
    {
        if (isprime[i]==0)
        {
            for (int j=i*i;j<=100005;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
int fin(int a)
{
    int co=0;
    int way=1;
    for (int i=2;i<=100000;i++)
    {
        if (isprime[i]==0&&a%i==0&&a>0)
        {
            co=1;
            while (a>0&&a%i==0)
            {
                a/=i;
                co++;
            }
            way*=co;
        }
        if (a==0)break;
    }
    return way;
}
int main()
{
    sieve();
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        cin>>a>>b;
        int best=0;
        int coun=0;
        int temp;
        for (int i=a;i<=b;i++)
        {
            temp=fin(i);
            if (temp>coun)
            {
                best=i;
                coun=temp;
            }
        }
        printf ("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,best,coun);
    }
}
