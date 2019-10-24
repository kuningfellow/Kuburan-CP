//UVA 11805 Bafana Bafana
#include <stdio.h>
int main()
{
    int t,kase=1;
    scanf("%d",&t);
    int a,b,c;
    while (t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf ("Case %d: %d\n",kase++,(b-1+c)%a+1);
    }
}
