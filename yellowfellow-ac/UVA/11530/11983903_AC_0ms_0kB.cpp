//UVA 11530 SMS Typing
#include <stdio.h>
#include <string.h>
int main()
{
    int tc,kas=1;
    scanf("%d",&tc);
    getchar();
    while (tc--)
    {
        char s[5000];
        scanf("%[^\n]s",s);
        getchar();
        int co=0,siz=strlen(s);
        for (int i=0;i<siz;i++)
        {
            if (s[i]==' ')co++;
            else
            {
                if (s[i]>='a'&&s[i]<='o')
                {
                    co+=((s[i]-'a')%3)+1;
                }
                else if (s[i]>='p'&&s[i]<='s')
                {
                    co+=s[i]-'p'+1;
                }
                else if (s[i]>='t'&&s[i]<='v')
                {
                    co+=s[i]-'t'+1;
                }
                else if (s[i]>='w')
                {
                    co+=s[i]-'w'+1;
                }
            }
        }
        printf ("Case #%d: %d\n",kas++,co);
    }
}
