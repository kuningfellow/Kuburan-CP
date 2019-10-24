#include <stdio.h>
int main()
{
    int t,kasus=1;
    scanf("%d",&t);
    while (t>0)
    {
        int a;
        int b,temp=0;
        scanf("%d",&a);
        int i;
        for (i=0;i<a;i++)
        {
            scanf("%d",&b);
            if (b>temp)
            {
                temp=b;
            }
        }
        printf ("Case %i: %d\n",kasus,temp);
        kasus++;
        t--;
    }
    return 0;
}
