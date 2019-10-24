#include <stdio.h>
int main()
{
    char c='0';
    int i=1;
    c=getchar();
    char t=c;
    int a=0;
    while (c!='\n')
    {
        c=getchar();
        if (c==t)i++;
        else i=1;
        if (i==7)a=1;
        t=c;
    }
    if (a==1)printf("YES\n");
    else printf ("NO\n");
    return 0;
}
