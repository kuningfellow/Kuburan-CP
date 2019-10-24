#include <stdio.h>
int main()
{
    int t=1;
    char s[1000005];
    s[0]='\0';
    while (scanf("%[^\n]s",s)!=EOF)
    {
        getchar();
        if (s[0]=='\0')break;
        int k;
        scanf("%d",&k);
        int i,j;
        int a,b;
        printf ("Case %i:\n",t);t++;
        for (i=0;i<k;i++)
        {
            int same=1;
            scanf("%d%d",&a,&b);
            if (a>b)
            {
                int temp=a;
                a=b;
                b=temp;
            }
            char flag;
            for (j=a;j<=b;j++)
            {
                if (j==a)flag=s[j];
                else if (s[j]!=flag)
                {
                    same=0;
                    break;
                }
            }
            if (same==1)printf ("Yes\n");
            else printf ("No\n");
        }
        getchar();
        s[0]='\0';
    }
    return 0;
}
