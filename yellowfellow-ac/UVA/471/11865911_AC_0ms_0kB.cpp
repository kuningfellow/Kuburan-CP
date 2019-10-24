//UVA 471 Magic Numbers
#include <stdio.h>
#include <iostream>
#include <vector>
int digit(long long int a)
{
    int mark[10];
    for (int i=0;i<10;i++)mark[i]=0;
    while (a>0)
    {
        mark[a%10]++;
        if (mark[a%10]>1)return 0;
        a/=10;
    }
    return 1;
}
int main()
{
    int tc;
    std::cin>>tc;
    while (tc--)
    {
        long long int n;
        std::cin>>n;
        for (long long int i=1;i*n<=10000000000;i++)
        {
            if (digit(i)&&digit(i*n))
            {
                printf ("%lld / %lld = %lld\n",i*n,i,n);
            }
        }
        if (tc>0)printf ("\n");
    }
}
