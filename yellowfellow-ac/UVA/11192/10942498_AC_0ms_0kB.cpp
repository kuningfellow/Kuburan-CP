#include <stdio.h>
#include <string.h>
void reverse (char s[],int a,int g)
{
    int i;
    char c;
    for (i=0;i<g/2;i++)
    {
        c=s[i+a];
        s[i+a]=s[g-1+a-i];
        s[g-1+a-i]=c;
    }
}
void divider (char s[],int g,int l)
{
    int i;
    for (i=0;i<l;i+=g)
    {
        reverse (s,i,g);
    }
}
int main()
{
    while (1<2)
    {
        int g;
        char s[105];
        scanf("%d",&g);
        if (g==0)break;
        scanf("%s",s);
        int l=strlen(s);
        g=l/g;
        divider (s,g,l);
        printf ("%s\n",s);
    }
    return 0;
}
