//UVA 584 Bowling
#include <stdio.h>
#include <string.h>
int main()
{
    while (1<2)
    {
        char s[500];
        scanf("%[^\n]s",s);
        getchar();
        if (!strcmp(s,"Game Over"))break;
        int round=0;
        int temp=0;
        int fir[12];
        int sec[12];
        int stri[12];
        for (int i=0;i<12;i++)
        {
            fir[i]=0;
            sec[i]=0;
            stri[i]=0;
        }
        int gam=0;
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                if (round==0)
                {
                    fir[gam]=s[i]-'0';
                    round=1;
                }
                else if (round==1)
                {
                    sec[gam]=s[i]-'0';
                    gam++;
                    round=0;
                }
            }
            if (s[i]=='/')
            {
                sec[gam]=10-fir[gam];
                stri[gam]=1;
                gam++;
                round=0;
            }
            if (s[i]=='X')
            {
                fir[gam]=10;
                stri[gam]=2;
                gam++;
                round=0;
            }
        }
        int tot=0;
        for (int i=0;i<gam;i++)
        {
            if (i<10)
            {
                tot+=fir[i]+sec[i];
                if (stri[i]==2)
                {
                    if (stri[i+1]==2)
                    {
                        tot+=fir[i+1]+fir[i+2];
                    }
                    else tot+=fir[i+1]+sec[i+1];
                }
                if (stri[i]==1)tot+=fir[i+1];
            }
        }
        printf ("%d\n",tot);
    }
}
