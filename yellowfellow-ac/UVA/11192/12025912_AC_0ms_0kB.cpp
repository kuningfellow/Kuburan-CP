//UVA 11192 Group Reverse
#include <stdio.h>
#include <string.h>
int main()
{
    while (1<2)
    {
        int n,siz;
        scanf("%d",&n);
        if (n==0)break;
        char s[102];
        scanf("%s",s);
        siz=strlen(s);
        n=siz/n;
        for (int i=0;i<siz;i++)
        {
            printf ("%c",s[i/n*n+n-1-i%n]);
        }
        printf ("\n");
    }
}
