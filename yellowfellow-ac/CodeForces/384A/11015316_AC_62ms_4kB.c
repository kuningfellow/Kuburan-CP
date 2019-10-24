#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int x=(n/2)*(n/2);
    if (n%2==1)
    {
        x+=(n/2+1)*(n/2+1);
    }
    else x*=2;
    printf("%d\n",x);
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if ((i+j)%2==0)
            printf ("C");
            else printf (".");
        }
        printf ("\n");
    }
    return 0;
}
