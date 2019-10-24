//UVA 10079 Pizza Cutting
#include <stdio.h>
int main()
{
    while (1<2)
    {
        long long int n;
        scanf("%lld",&n);
        if (n<0)break;
        long long int now=1;
        for (long long int i=0;i<n;i++)
        {
            now+=i+1;
        }
        printf ("%lld\n",now);
    }
}
