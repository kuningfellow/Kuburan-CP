#include <stdio.h>
#include <vector>
using namespace std;
vector<int>primes;
void primefind(int a)
{
    int i,j,isprime=1;
    for (i=primes[primes.size()-1]+1;i<=a;i++)
    {
        isprime=1;
        for (j=0;j<primes.size();j++)
        {
            if (i%primes[j]==0)
            {
                isprime=0;
            }
        }
        if (isprime==1)
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    primes.push_back(2);
    primes.push_back(3);
    int i,j,n,coun;
    while (1<2)
    {
        coun=0;
        scanf("%d",&n);
        if (n==0)break;
        primefind(n);
        for (i=0;primes[i]<n;i++)
        {
            for (j=i;primes[j]<n;j++)
            {
                if (primes[i]+primes[j]==n)
                {
                    coun++;
                }
            }
        }
        printf ("%d\n",coun);
    }
    return 0;
}
