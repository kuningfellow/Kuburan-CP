//UVA 11221 Magic square palindromes.
#include <stdio.h>
#include <string.h>
int magic(int a)
{
    for (int i=1;i*i<=a;i++)
    {
        if (i*i==a)return i;
    }
    return 0;
}
int main()
{
    int tc,kas=1;
    scanf("%d",&tc);
    getchar();
    while (tc--)
    {
        char s[10005];
        scanf("%[^\n]s",s);
        getchar();
        if (strlen(s)==4&&s[0]=='D'&&s[1]=='O'&&s[2]=='N'&&s[3]=='E')
            break;
        int l=0;
        int r=strlen(s)-1;
        int yes=1;
        int bad=0;
        while (l<r)
        {
            while (!((s[l]>='A'&&s[l]<='Z')||(s[l]>='a'&&s[l]<='z')))
            {
                bad++;
                l++;
            }
            while (!((s[r]>='A'&&s[r]<='Z')||(s[r]>='a'&&s[r]<='z')))
            {
                bad++;
                r--;
            }
            if (s[l]!=s[r]&&s[l]!=s[r]-'A'+'a'&&s[l]-'A'+'a'!=s[r])
            {
                yes=0;
                break;
            }
            l++;
            r--;
        }
        int res=magic(strlen(s)-bad);
        printf ("Case #%d:\n",kas++);
        if (yes==1&&res)printf ("%d\n",res);
        else printf ("No magic :(\n");
    }
}
