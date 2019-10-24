#include <stdio.h>
int main()
{
    int x;
    scanf ("%d",&x);
    int s=0;
    int i;
    for (i=5;i>0;i--)
    {
        s+=x/i;
        x=x%i;
    }
    printf ("%i",s);
}
