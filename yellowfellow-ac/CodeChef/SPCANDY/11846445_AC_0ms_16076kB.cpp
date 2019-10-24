#include <stdio.h>
int main()
{
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        if (b==0)printf ("%lld %lld\n",0,a);
        else printf ("%lld %lld\n",a/b,a%b);
    }
    return 0;
}
