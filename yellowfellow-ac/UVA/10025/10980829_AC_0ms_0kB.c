#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int a;
        scanf("%d",&a);
        int i=1;
        int n=2;
        if (a<0)a=-a;
        while (1<2)
        {
            if (i>=a&&(i-a)%2==0)
            {
                break;
            }
            i+=n;
            n++;
        }
        n--;
        printf ("%d\n",n);
        if (t>1)printf ("\n");
        t--;
    }
    return 0;
}
