#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int conv[26];
int main()
{
    int tc;
    cin>>tc;
    char s[500];
    scanf("%s",s);
    getchar();
    for (int i=0;i<strlen(s);i++)
    {
        conv[i]=s[i]-'a';
    }
    while (tc--)
    {
        scanf("%[^\n]s",s);
        getchar();
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]>='A'&&s[i]<='Z')
            {
                printf ("%c",conv[s[i]-'A']+'A');
            }
            else if (s[i]>='a'&&s[i]<='z')
            {
                printf ("%c",conv[s[i]-'a']+'a');
            }
            else if (s[i]=='_')printf (" ");
            else printf ("%c",s[i]);
        }
        printf ("\n");
    }
}
