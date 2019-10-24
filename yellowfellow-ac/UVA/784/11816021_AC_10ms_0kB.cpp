//UVA 784 Maze Exploration
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
char ma[31][81];
int he=0;
void fil(int x, int y)
{
    ma[x][y]='#';
    if (ma[x+1][y]==' ')fil(x+1,y);
    if (ma[x-1][y]==' ')fil(x-1,y);
    if (ma[x][y+1]==' ')fil(x,y+1);
    if (ma[x][y-1]==' ')fil(x,y-1);
}
int main()
{
    int tc;
    cin>>tc;
    getchar();
    while (tc--)
    {
        he=0;
        char c[81];
        int x0,y0;
        while (1<2)
        {
            c[0]='\0';
            scanf("%[^\n]s",c);
            getchar();
            int done=1;
            strcpy(ma[he],c);
            for (int i=0;i<strlen(c);i++)
            {
                if (c[i]!='_')
                {
                    done=0;
                }
                if (c[i]=='*')
                {
                    x0=he;
                    y0=i;
                }
            }
            he++;
            if (done==1)break;
        }
        fil(x0,y0);
        for (int i=0;i<he;i++)
        {
            for (int j=0;j<strlen(ma[i]);j++)
            {
                printf ("%c",ma[i][j]);
            }
            printf ("\n");
        }
    }
}
