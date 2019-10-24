#include<stdio.h>
int main()
{
    int x=0;
    char z[100];
    char c;
    int i;
    while (c!='\n')
    {
        c=getchar();
        z[x]=c;
        x++;
    }
    x--;
    for (i=0;i<x;i++)
    {
        if (z[i]=='A'||z[i]=='a'||z[i]=='O'||z[i]=='o'||z[i]=='Y'||z[i]=='y'||z[i]=='E'||z[i]=='e'||z[i]=='U'||z[i]=='u'||z[i]=='I'||z[i]=='i')
        {
            z[i]='\n';
        }
    }
    for (i=0;i<x;i++)
    {
        if (z[i]>='A'&&z[i]<='Z')
        {
            z[i]+=32;
        }
    }
    for (i=0;i<x;i++)
    {
        if (z[i]!='\n')
        printf (".%c",z[i]);
    }
}
