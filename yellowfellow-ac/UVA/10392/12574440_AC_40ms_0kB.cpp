#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    long long int n;
    while (1<2)
    {
        scanf("%lld",&n);
        if (n<0)break;
        for (long long int i=2;i*i<=n;i++)
        {
            while (n%i==0)
            {
                printf ("    %lld\n",i);
                n/=i;
            }
        }
        if (n>1)
            printf ("    %lld\n",n);
        printf ("\n");
    }
}
