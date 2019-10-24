#include <stdio.h>
int main()
{
    char a[105];
    scanf("%s",a);
    char b[105];
    scanf("%s",b);
    if (strlen(a)!=strlen(b))
    {
        printf ("NO\n");
    }
    else
    {
        int i;
        for (i=0;i<strlen(a);i++)
        {
            if (a[i]!=b[strlen(a)-i-1])
            {
                printf ("NO\n");
                break;
            }
            if (i==strlen(a)-1)
            {
                printf ("YES\n");
                break;
            }
        }
    }
    return 0;
}
