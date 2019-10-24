#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int i=0;
    while (1<2)
    {
        if (b%a==0)
        {
            if (b>=a)
            {
                b/=a;
                i++;
            }
            if (b==1)
            {
                printf ("YES\n%d\n",i-1);
                break;
            }
        }
        else
        {
            printf ("NO\n");
            break;
        }
    }
    return 0;
}
