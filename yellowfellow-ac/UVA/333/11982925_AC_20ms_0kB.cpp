//UVA 333 Recognizing Good ISBNs
#include <stdio.h>
#include <string.h>
int main()
{
    char s[500];
    s[0]='\0';
    while (scanf("%[^\n]s",s)!=EOF)
    {
        getchar();
        int a=0,sum=0,siz=strlen(s);
        int ar[10];
        int in=0;
        for (int i=0;i<siz;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                sum+=s[i]-'0';
                if (in<10)
                {
                    ar[in]=sum;
                }
                else in=100;
                in++;
            }
            if (s[i]=='X')
            {
                sum+=10;
                if (in==9)
                {
                    ar[in]=sum;
                }
                else
                {
                    in=100;
                }
                in++;
            }
        }
        sum=0;
        for (int i=0;i<10;i++)
        {
            sum+=ar[i];
        }
        int init=1;
        int se=0;
        for (int i=0;i<siz;i++)
        {
            if (s[i]!=' ')
            {
                init=0;
                for (int j=0;j<se;j++)printf (" ");
                se=0;
                printf ("%c",s[i]);
            }
            if (s[i]==' '&&init==0)
            {
                se++;
            }
        }
        if (sum%11==0&&in==10)
        {
            printf (" is correct.\n");
        }
        else printf (" is incorrect.\n");
        s[0]='\0';
    }
}
