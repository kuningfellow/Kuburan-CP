#include <stdio.h>
int main()
{
    int t,a,b,i;
    scanf("%d",&t);
    getchar();
    for (i=0;i<t;i++)
    {
        scanf ("%d%d",&a,&b);
        getchar();
        printf ("%i\n",a+b);
    }
}
