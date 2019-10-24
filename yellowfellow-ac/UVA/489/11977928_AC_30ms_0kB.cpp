//UVA 489 Hangman Judge
#include <stdio.h>
#include <string.h>
int main()
{
    while (1<2)
    {
        char s[500];
        char p[500];
        int eh;
        scanf("%d",&eh);
        if (eh==-1)break;
        scanf("%s%s",s,p);
        int cor[26];
        int ans[26];
        for (int i=0;i<26;i++)
        {
            ans[i]=0;
            cor[i]=0;
        }
        for (int i=0;i<strlen(s);i++)
        {
            cor[s[i]-'a']=1;
        }
        int mov=0;
        int in=0;
        while (in<strlen(p))
        {
            if (ans[p[in]-'a']==0)
            {
                if (cor[p[in]-'a']==0)mov++;
                cor[p[in]-'a']=0;
                ans[p[in]-'a']=1;
                if (mov>=7)break;
            }
            in++;
        }
        int solv=0;
        for (int i=0;i<26;i++)
        {
            solv+=cor[i];
        }
        printf ("Round %d\n",eh);
        if (solv==0)printf ("You win.\n");
        else if (mov>=7)printf ("You lose.\n");
        else printf ("You chickened out.\n");
    }
}
