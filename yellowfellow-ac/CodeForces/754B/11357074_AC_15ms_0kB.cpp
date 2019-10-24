#include <stdio.h>
char ma[4][4];
int main()
{
    int i,j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            scanf("%c",&ma[i][j]);
        }
        getchar();
    }
    int done=0;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if (ma[i][j]=='x')
            {
                if (i+2<4&&((ma[i+1][j]=='.'&&ma[i+2][j]=='x')||(ma[i+1][j]=='x'&&ma[i+2][j]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (i-1>=0&&i+1<4&&((ma[i-1][j]=='.'&&ma[i+1][j]=='x')||(ma[i-1][j]=='x'&&ma[i+1][j]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (j+2<4&&((ma[i][j+1]=='.'&&ma[i][j+2]=='x')||(ma[i][j+1]=='x'&&ma[i][j+2]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (j-1>=0&&j+1<4&&((ma[i][j-1]=='.'&&ma[i][j+1]=='x')||(ma[i][j-1]=='x'&&ma[i][j+1]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (i+2<4&&j+2<4&&((ma[i+1][j+1]=='.'&&ma[i+2][j+2]=='x')||(ma[i+1][j+1]=='x'&&ma[i+2][j+2]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (i-1>=0&&j-1>=0&&i+1<4&&j+1<4&&((ma[i-1][j-1]=='.'&&ma[i+1][j+1]=='x')||(ma[i-1][j-1]=='x'&&ma[i+1][j+1]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (i+2<4&&j-2>=0&&((ma[i+1][j-1]=='.'&&ma[i+2][j-2]=='x')||(ma[i+1][j-1]=='x'&&ma[i+2][j-2]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
                if (i-1>=0&&j+1<4&&i+1<4&&j-1>=0&&((ma[i-1][j+1]=='.'&&ma[i+1][j-1]=='x')||(ma[i-1][j+1]=='x'&&ma[i+1][j-1]=='.')))
                {
                    printf ("YES\n");
                    done=1;
                    break;
                }
            }
            if (done==1) break;
        }
        if (done==1)break;
    }
    if (done==0)printf ("NO\n");
    return 0;
}
