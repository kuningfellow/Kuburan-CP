//UVA 12149 Feynman
#include <stdio.h>
int funx(int a,int n)
{
    if (a==n)return 1;
    return (n+1-a)*(n+1-a)+funx(a+1,n);
}
int main()
{
    int n;
    while (1<2)
    {
        scanf("%d",&n);
        if (n==0)break;
        printf ("%d\n",funx(1,n));
    }
}
