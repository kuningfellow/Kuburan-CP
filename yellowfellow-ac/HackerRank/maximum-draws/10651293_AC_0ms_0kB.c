#include <stdio.h>
int main()
{
    int n,t;
    scanf ("%d",&t);
    int i;
    for (i=0;i<t;i++)
    {
        scanf ("%d",&n);
        n=n*2;
        int b;
        b=(n/2)+1;
        printf ("%i\n",b);
    }
}
