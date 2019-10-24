#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int primes[5000];
int fin()
{
    for (int i=3;i<5000;i++)
    {
        int bad=0;
        for (int j=2;j*j<=i;j++)
        {
            if (i%j==0)
            {
                bad=1;
                break;
            }
        }
        if (bad==0)
        {
            primes[i]=1;
        }
    }
}
int main()
{
    fin();
    primes[1]=1;
    primes[2]=1;
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a+=b;
        int ad=1;
        while (1<2)
        {
            if (primes[a+ad]==1)
            {
                break;
            }
            ad++;
        }
        printf ("%d\n",ad);
    }
}
