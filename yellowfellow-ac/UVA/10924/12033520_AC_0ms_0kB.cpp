//UVA 10924 Prime Words
#include <stdio.h>
int primesi[5000];
int siev(int s)
{
    for (int i=2;i*s<5000;i++)
    {
        primesi[i*s]=1;
    }
}
int main()
{
    for (int i=2;i<=71;i++)
    {
        siev(i);
    }
    char c;
    int val=0;
    while (scanf("%c",&c)!=EOF)
    {
        if (c>='a'&&c<='z')
        {
            val+=c-'a'+1;
        }
        else if (c>='A'&&c<='Z')
        {
            val+=c-'A'+27;
        }
        else
        {
            if (primesi[val]==0)printf ("It is a prime word.\n");
            else printf ("It is not a prime word.\n");
            val=0;
        }
    }
}
