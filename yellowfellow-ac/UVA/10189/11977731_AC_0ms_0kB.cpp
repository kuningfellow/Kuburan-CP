//UVA 10189 Minesweeper
#include <stdio.h>
char ar[101][101];
int main()
{
    int kas=1;
    while (1<2)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        for (int i=0;i<n;i++)
        {
            scanf("%s",ar[i]);
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                int adj=0;
                if (ar[i][j]=='*')continue;
                for (int k=-1;k<=1;k++)
                {
                    for (int l=-1;l<=1;l++)
                    {
                        if (i+k>=0&&i+k<n&&j+l>=0&&j+l<m&&ar[i+k][j+l]=='*')adj++;
                    }
                }
                ar[i][j]=adj+'0';
            }
        }
        if (kas>1)printf ("\n");
        printf ("Field #%d:\n",kas++);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                printf ("%c",ar[i][j]);
            }
            printf ("\n");
        }
    }
}
