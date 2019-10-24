//UVA 11614 Etruscan Warriors Never Play Chess
#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    long long int w;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&w);
        printf ("%d\n",((-1+(long long int)sqrt(1+8*w))/2));
    }
}
