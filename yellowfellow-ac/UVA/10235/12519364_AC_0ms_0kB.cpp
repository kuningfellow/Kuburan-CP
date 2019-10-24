#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool isprime[1100000];
void sieve()
{
    for (int i=2;i*i<=1000005;i++)
    {
        if (isprime[i]==0)
        {
            for (int j=i*2;j<=1000005;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int rev=0;
        int sav=n;
        while (n>0)
        {
            rev*=10;
            rev+=(n%10);
            n/=10;
        }
        if (isprime[sav]==0&&isprime[rev]==0&&rev!=sav)printf ("%d is emirp.\n",sav);
        else if (isprime[sav]==0)printf ("%d is prime.\n",sav);
        else printf ("%d is not prime.\n",sav);
    }
}
