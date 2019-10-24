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
        char s[1001];
        scanf("%s",s);
        int freqb[26];
        int freqa[26];
        for (int i=0;i<26;i++)
        {
            freqa[i]=0;
            freqb[i]=0;
        }
        int siz=strlen(s);
        for (int i=0;i<siz/2;i++)
        {
            freqa[s[i]-'a']++;
            freqb[s[siz-i-1]-'a']++;
        }
        int same=1;
        for (int i=0;i<26;i++)
        {
            if (freqa[i]!=freqb[i])
            {
                same=0;
                break;
            }
        }
        if (same==1)printf ("YES\n");
        else printf ("NO\n");
    }
}
