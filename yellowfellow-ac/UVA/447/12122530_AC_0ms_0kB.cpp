//UVA 447 Population Explosion
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char pl[20][20];
int niu[20][20];
int surv(int a, int b)
{
    int ne=0;
    for (int i=-1;i<=1;i++)
    {
        for (int j=-1;j<=1;j++)
        {
            if ((i!=0||j!=0)&&a+i<20&&a+i>=0&&b+j<20&&b+j>=0)
            {
                niu[a+i][b+j]++;
                if (pl[a+i][b+j]!=' ')
                {
                    ne++;
                }
            }
        }
    }
    return ne;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int y;
        cin>>y;
        getchar();
        int a,b;
        for (int i=0;i<20;i++)
        {
            for (int j=0;j<20;j++)
            {
                pl[i][j]=' ';
                niu[i][j]=0;
            }
        }
        char temp[500];
        while (1<2)
        {
            temp[0]='\0';
            scanf("%[^\n]",temp);
            getchar();
            int ex=0;
            int ey=0;
            if (strlen(temp)>0)
            {
                for (int i=0;i<strlen(temp);i++)
                {
                    if (temp[i]>='0'&&temp[i]<='9')
                    {
                        ey*=10;
                        ey+=temp[i]-'0';
                    }
                    else
                    {
                        ex=ey;
                        ey=0;
                    }
                }
            }
            else
            {
                break;
            }
            pl[ex-1][ey-1]='O';
        }
        for (int k=0;k<y;k++)
        {
            if (k<y)
            {
                for (int i=0;i<20;i++)printf ("*");
                printf ("\n");
            }
            for (int i=0;i<20;i++)
            {
                for (int j=0;j<20;j++)
                {
                    printf ("%c",pl[i][j]);
                    if (pl[i][j]=='O')
                    {
                        int ne=surv(i,j);
                        if (ne<=1||ne>=4)
                        {
                            pl[i][j]='d';
                        }
                    }
                }
                printf ("\n");
            }
            for (int i=0;i<20;i++)
            {
                for (int j=0;j<20;j++)
                {
                    if (pl[i][j]=='d')pl[i][j]=' ';
                    if (niu[i][j]==3)pl[i][j]='O';
                    niu[i][j]=0;
                }
            }
        }
        for (int i=0;i<20;i++)printf ("*");
        printf ("\n");
        if (tc>0)printf ("\n");
    }
}
