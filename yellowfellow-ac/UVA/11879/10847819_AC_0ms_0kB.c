#include <stdio.h>
#include <string.h>
int main()
{
    char a[105];
    while (1<2)
    {
        scanf("%s",a);
        int i=strlen(a)-1;
        if (i==0&&a[i]=='0')
        {
            break;
        }
        int num=0,j=1;
        for (;i>=0;i--)
        {
            num+=(a[i]-'0')*j;
            j*=10;
            if (num>=100)
            {
                int t=num%10;
                num/=10;
                num-=5*t;
                j/=10;
            }
        }
        if (num%17==0)
        {
            printf ("1\n");
        }
        else printf ("0\n");
    }
    return 0;
}
