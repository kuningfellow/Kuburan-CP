//UVA 12555 Baby Me
#include <stdio.h>
#include <string.h>
int main()
{
    int tc,kas=1;
    scanf("%d",&tc);
    getchar();
    while (tc--)
    {
        char s[500];
        scanf("%[^\n]s",s);
        getchar();
        int ar[2]={0,0};
        int num=0;
        int flag=1;
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                flag=0;
                ar[num]*=10;
                ar[num]+=s[i]-'0';
            }
            else
            {
                if (flag==0)
                {
                    num++;
                    flag=1;
                }
            }
        }
        int sub=(ar[0]*50+ar[1]*5)%100;
        while (sub%10==0&&sub>0)sub/=10;
        if (sub==0)printf ("Case %d: %d\n",kas++,(ar[0]*50+ar[1]*5)/100);
        else printf ("Case %d: %d.%d\n",kas++,(ar[0]*50+ar[1]*5)/100,sub);
    }
}
