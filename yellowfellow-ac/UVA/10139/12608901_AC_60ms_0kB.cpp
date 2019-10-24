#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[50000];
int primes[5200];
int siz=0;
void sieve()
{
    for (int i=2;i<50000;i++)
    {
        if (isprime[i]==0)
        {
            primes[siz++]=i;
            for (int j=i*2;j<50000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
vector<int>de;
vector<int>coun;
int main()
{
    sieve();
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if (a>b)printf ("%d divides %d!\n",b,a);
        else
        {
            int co;
            int rem=b;
            for (int i=0;i<siz;i++)
            {
                co=0;
                while (rem%primes[i]==0)
                {
                    rem/=primes[i];
                    co++;
                }
                if (co>0)
                {
                    de.push_back(primes[i]);
                    coun.push_back(co);
                }
                if (rem==1)break;
            }
            if (rem>1)
            {
                de.push_back(rem);
                coun.push_back(1);
            }
            int red=0;
            int l=de.size();
            int good=1;
            for (int i=0;i<l;i++)
            {
                for (int j=de[i];j<=a;j+=de[i])
                {
                    red=j;
                    while (red%de[i]==0)
                    {
                        red/=de[i];
                        coun[i]--;
                    }
                    if (coun[i]<=0)break;
                }
                if (coun[i]>0)
                {
                    good=0;
                    break;
                }
            }
            if (good==1)printf ("%d divides %d!\n",b,a);
            else printf ("%d does not divide %d!\n",b,a);
            de.clear();
            coun.clear();
        }
    }
}
