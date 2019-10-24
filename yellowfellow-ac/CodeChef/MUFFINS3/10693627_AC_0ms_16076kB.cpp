#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int t;
    int i;
    for (i=0;i<n;i++)
    {
        scanf ("%d",&t);
        printf ("%i\n",t/2+1);
    }
}
