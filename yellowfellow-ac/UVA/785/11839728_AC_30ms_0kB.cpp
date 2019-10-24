//UVA 785 Grid Colouring
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
char ma[82][82];
int done[82][82];
int siz=0;
int dfs(int x, int y, char c)
{
    if (done[x][y]==0&&(ma[x][y]==' '||ma[x][y]==c))
    {
        ma[x][y]=c;
        done[x][y]=1;
    }
    else return 0;
    dfs(x+1,y,c);
    dfs(x,y+1,c);
    dfs(x-1,y,c);
    dfs(x,y-1,c);
}
int main()
{
	int sel=0;
    while (1<2)
    {
        siz=0;
        int fa=0;
        char fir;
        while (1<2)
        {
        	ma[siz][0]='\0';
            if (scanf("%[^\n]s",ma[siz])==EOF)
			{
				sel=1;
				break;
			}
			getchar();
			int en=strlen(ma[siz]);
			ma[siz][en]='\n';
			ma[siz][en+1]='\0';
			if (sel==1)break;
            int don=1;
            for (int i=0;i<strlen(ma[siz]);i++)
            {
                done[siz][i]=0;
                if (ma[siz][i]!='_'&&ma[siz][i]!='\n')
                {
                    don=0;
                }
                if (fa==0&&ma[siz][i]!=' '&&ma[siz][i]!='\n')
                {
                	fa=1;
                	fir=ma[siz][i];
				}
            }
            siz++;
            if (don==1)break;
        }
        if (sel==1)break;
        for (int i=0;i<siz;i++)
        {
            for (int j=0;j<strlen(ma[i]);j++)
            {
                if (ma[i][j]!=' '&&ma[i][j]!=fir&&ma[i][j]!='_'&&ma[i][j]!='\n')
                {
                    dfs(i,j,ma[i][j]);
                }
            }
        }
        for (int i=0;i<siz;i++)
        {
            printf ("%s",ma[i]);
        }
    }
}