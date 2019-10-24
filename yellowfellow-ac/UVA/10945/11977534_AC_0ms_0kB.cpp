//UVA 10945 Mother bear
#include <stdio.h>
#include <string.h>
int main()
{
    while (1<2)
    {
        char s[5000];
        scanf("%[^\n]s",s);
        getchar();
        if (strlen(s)==4&&s[0]=='D'&&s[1]=='O'&&s[2]=='N'&&s[3]=='E')
            break;
        int l=0;
        int r=strlen(s)-1;
        int yes=1;
        while (l<r)
        {
            while (!((s[l]>='A'&&s[l]<='Z')||(s[l]>='a'&&s[l]<='z')))l++;
            while (!((s[r]>='A'&&s[r]<='Z')||(s[r]>='a'&&s[r]<='z')))r--;
            if (s[l]!=s[r]&&s[l]!=s[r]-'A'+'a'&&s[l]-'A'+'a'!=s[r])
            {
                yes=0;
                break;
            }
            l++;
            r--;
        }
        if (yes==1)printf ("You won't be eaten!\n");
        else printf ("Uh oh..\n");
    }
}
