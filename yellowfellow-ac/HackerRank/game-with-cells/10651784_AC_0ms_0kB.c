#include <stdio.h>
int main()
{
    int a,b;
    scanf ("%d %d",&a,&b);
    if (a%2==1)
    {
        a++;
    }
    if (b%2==1)
    {
        b++;
    }
    a=a/2;
    b=b/2;
    printf ("%i",a*b);
}
