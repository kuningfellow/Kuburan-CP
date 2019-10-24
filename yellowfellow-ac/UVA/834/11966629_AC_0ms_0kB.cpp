//UVA 834 Continued Fractions
#include <stdio.h>
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        int temp;
        printf ("[%d;",a/b);
        a%=b;
        while (1<2)
        {
            printf ("%d",b/a);
            temp=a;
            a=b%a;
            if (a==0)
            {
                printf ("]");
                break;
            }
            else printf (",");
            b=temp;
        }
        printf ("\n");
    }
}
