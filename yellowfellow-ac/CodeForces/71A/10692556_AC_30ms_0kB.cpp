#include <stdio.h>
int main()
{
    char a[100];
    int i;
    char c;
    int t,j,n;
    scanf("%i",&t);
    getchar();
    for(n=0;n<t;n++)
    {
        i=0;
        while (c!='\n')
        {
            scanf("%c",&c);
            a[i]=c;
            i++;
        }
        c='0';
        j=i-3;
        if (i>11)
        {
            printf ("%c%i%c\n",a[0],j,a[i-2]);
        }
        else
        {
            int j;
            for(j=0;j<i;j++)
            printf("%c",a[j]);
        }
    }
}
