//608 Counterfeit Dollar
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        char left[3][50];
        char right[3][50];
        int rel[3];
        char s[500];
        for (int i=0;i<3;i++)
        {
            scanf("%s",left[i]);
            scanf("%s",right[i]);
            scanf("%s",s);
            if (!strcmp(s,"even"))rel[i]=0;
            else if (!strcmp(s,"up"))rel[i]=1;
            else if (!strcmp(s,"down"))rel[i]=-1;
        }
        int liglef,ligrig,hevlef,hevrig,yayl,yayh,ans,mode=0;
        for (int i=0;i<12;i++)
        {
            yayl=0;
            yayh=0;
            for (int j=0;j<3;j++)
            {
                liglef=0;
                ligrig=0;
                hevlef=0;
                hevrig=0;
                for (int k=0;k<strlen(left[j]);k++)
                {
                    if (left[j][k]-'A'==i)
                    {
                        liglef--;
                        hevlef++;
                    }
                }
                for (int k=0;k<strlen(right[j]);k++)
                {
                    if (right[j][k]-'A'==i)
                    {
                        ligrig--;
                        hevrig++;
                    }
                }
                if (liglef==rel[j]+ligrig)
                {
                    yayl++;
                }
                if (hevlef==rel[j]+hevrig)
                {
                    yayh++;
                }
            }
            if (yayl==3)
            {
                ans=i;
                mode=-1;
            }
            if (yayh==3)
            {
                ans=i;
                mode=1;
            }
        }
        if (mode==-1)
            printf ("%c is the counterfeit coin and it is light.\n",ans+'A');
        else if (mode==1)
            printf ("%c is the counterfeit coin and it is heavy.\n",ans+'A');
    }
}
