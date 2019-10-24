#include <stdio.h>
int vowel(char c)
{
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    else return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        char a[25];
        char b[25];
        int same=1;
        scanf("%s%s",a,b);
        int j=strlen(a);
        if (strlen(a)!=strlen(b))
        {
            same=0;
        }
        else
        {
            int i;
            for (i=0;i<j;i++)
            {
                if (!vowel(a[i]))
                {
                    if (b[i]!=a[i])
                    {
                        same=0;
                        break;
                    }
                }
            }
        }
        if (same==1)
        {
            printf ("Yes\n");
        }
        else printf ("No\n");
        t--;
    }
return 0;
}
