#include <stdio.h>
int main()
{
    int m,n;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        int a,b;
        a=m-1+(m*(n-1));
        b=n-1+(n*(m-1));
        printf ("%i\n",a<b?a:b);
    }
return 0;
}
