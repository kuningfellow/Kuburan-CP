//UVA 10281 Average Speed
#include <stdio.h>
#include <string.h>
int main()
{
    char s[50];
    int t[3];
    int tp[3];
    for (int i=0;i<3;i++){t[i]=0;tp[i]=0;}
    int ti=0;
    int v=0;
    int tv=0;
    double d=0;
    while (scanf("%[^\n]s",&s)!=EOF)
    {
        getchar();
        ti=0;
        for (int i=0;i<strlen(s);i++)
        {
            if (ti<3&&s[i]>='0'&&s[i]<='9')
            {
                t[ti]*=10;
                t[ti]+=s[i]-'0';
            }
            else if (ti==3&&s[i]>='0'&&s[i]<='9')
            {
                tv*=10;
                tv+=s[i]-'0';
            }
            else
            {
                if (ti<3)
                    ti++;
                if (ti==3)tv=0;
            }
        }
        s[0]='\0';
        if ((t[0]*3600+t[1]*60+t[2]-tp[0]*3600-tp[1]*60-tp[2])>0)
        {
            d+=((double)(t[0]*3600+t[1]*60+t[2]-tp[0]*3600-tp[1]*60-tp[2]))*v/3600;
        }
        if (ti!=3)
        {
            printf ("%02d:%02d:%02d %.2f km\n",t[0],t[1],t[2],d);
        }
        v=tv;
        tp[0]=t[0];
        tp[1]=t[1];
        tp[2]=t[2];
        t[0]=0;
        t[1]=0;
        t[2]=0;
    }
}
