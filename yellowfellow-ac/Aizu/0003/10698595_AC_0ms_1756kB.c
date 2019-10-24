#include<stdio.h>
int main()
{
    int a,b,c;
    int i;
    scanf("%d",&i);
    while (i>0)
    {
        scanf("%d%d%d",&a,&b,&c);
        if ((a*a)+(b*b)==(c*c)||(b*b)+(c*c)==(a*a)||(c*c)+(a*a)==(b*b))
        {
            printf ("YES\n");
        }
        else printf ("NO\n");
        i--;

    }
}
