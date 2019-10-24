#include <stdio.h>
int main()
{
    int t=1;
    char s[205];
    while (scanf("%[^\n]s",s)!=EOF)
    {
        getchar();
        int ma[3][3];
        int i,j,k;
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                ma[i][j]=0;
            }
        }
        int l=strlen(s);
        if (l>0)
        {
            for (i=0;i<l;i++)
            {
                j=0;
                if (s[i]>='a'&&s[i]<='z')
                    k=s[i]-'a';
                else continue;
                while (k>2)
                {
                    j++;
                    k-=3;
                }
                if (k+1<3)ma[j][k+1]++;
                if (j+1<3)ma[j+1][k]++;
                if (k-1>=0)ma[j][k-1]++;
                if (j-1>=0)ma[j-1][k]++;
                ma[j][k]++;
            }
        }
        printf ("Case #%i:\n",t);t++;
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                ma[i][j]%=10;
                printf ("%d",ma[i][j]);
                if (j<2)printf (" ");
            }
            printf ("\n");
        }
        s[0]='\0';
    }
    return 0;
}
