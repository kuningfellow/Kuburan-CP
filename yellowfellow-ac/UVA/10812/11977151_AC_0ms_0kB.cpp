//UVA 10812 Beat the Spread!
#include <stdio.h>
int main()
{
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        if (a<b||(a+b)%2==1||(a-b)%2==1)printf ("impossible\n");
        else printf ("%lld %lld\n",(a+b)/2,(a-b)/2);
    }
}
