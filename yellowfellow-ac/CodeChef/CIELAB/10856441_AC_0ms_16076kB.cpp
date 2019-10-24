#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a-b;
    if (c%10==9)
    {
        c--;
        printf ("%i",c);
    }
    else
    {
        c++;
        printf("%i",c);
    }
    return 0;
}
