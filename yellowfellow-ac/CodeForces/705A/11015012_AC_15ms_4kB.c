#include <stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    int w=1;
    printf ("I hate");
    w++;
    while (w<=i)
    {
        if (w%2==0)
            printf (" that I love");
        else printf (" that I hate");
        w++;
    }
    printf (" it\n");
    return 0;
}
