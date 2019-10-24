//UVA 673 Parentheses Balance
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    getchar();
    while (t--)
    {
        char s[500];
        s[0]='\0';
        scanf("%[^\n]s",s);
        if (strlen(s)==0)
        {
            printf ("Yes\n");
            getchar();
            continue;
        }
        getchar();
        int done=0;
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]!='('&&s[i]!=')'&&s[i]!='['&&s[i]!=']')
            {
                printf ("No\n");
                done=1;
                break;
            }
        }
        if (done==1)continue;
        int mode=0;
        int prev=0;
        while (1<2)
        {
            int kill=0;
            mode=0;
            for (int i=0;i<strlen(s);i++)
            {
                if (s[i]=='(')
                {
                    mode=1;
                    prev=i;
                }
                else if (s[i]==')'&&mode==1)
                {
                    s[prev]=' ';
                    s[i]=' ';
                    mode=0;
                    kill=1;
                }
                else if (s[i]=='[')
                {
                    mode=2;
                    prev=i;
                }
                else if (s[i]==']'&&mode==2)
                {
                    s[prev]=' ';
                    s[i]=' ';
                    mode=0;
                    kill=1;
                }
                else if (s[i]!=' ')
                {
                    mode=0;
                }
            }
            if (kill==0)break;
        }
        int bad=0;
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]!=' ')
            {
                bad=1;
                printf ("No\n");
                break;
            }
        }
        if (bad==0)
        {
            printf ("Yes\n");
        }
    }
}
