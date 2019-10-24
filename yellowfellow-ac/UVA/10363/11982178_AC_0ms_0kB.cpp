//UVA 10363 Tic Tac Toe
#include <stdio.h>
int main()
{
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        char ma[4][4];
        for (int i=0;i<3;i++)
        {
            scanf("%s",ma[i]);
        }
        int o=0;
        int x=0;
        int owin=0;
        int xwin=0;
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                if (ma[i][j]=='O')o++;
                if (ma[i][j]=='X')x++;
            }
        }
        for (int i=0;i<3;i++)
        {
            if (ma[i][1]==ma[i][2]&&ma[i][0]==ma[i][1])
            {
                if (ma[i][1]=='O')owin++;
                if (ma[i][1]=='X')xwin++;
            }
            if (ma[1][i]==ma[2][i]&&ma[0][i]==ma[1][i])
            {
                if (ma[1][i]=='O')owin++;
                if (ma[1][i]=='X')xwin++;
            }
        }
        if (ma[0][0]==ma[1][1]&&ma[1][1]==ma[2][2])
        {
            if (ma[0][0]=='O')owin++;
            if (ma[0][0]=='X')xwin++;
        }
        if (ma[0][2]==ma[1][1]&&ma[2][0]==ma[1][1])
        {
            if (ma[1][1]=='O')owin++;
            if (ma[1][1]=='X')xwin++;
        }
        if (xwin==0&&owin>=0&&o==x)printf ("yes\n");
        else if (o+1!=x)printf ("no\n");
        else if (owin>=1)printf ("no\n");
        else printf ("yes\n");
    }
}
