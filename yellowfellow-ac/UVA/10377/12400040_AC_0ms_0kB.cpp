//UVA 10377 Maze Traversal
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ma[65][65];
int n,m;
int main()
{
    int tc,fir=0;
    cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        getchar();
        char rem[500];
        for (int i=0;i<n;i++)
        {
            scanf("%[^\n]s",rem);
            getchar();
            for (int j=0;j<m;j++)
            {
                if (rem[j]=='*')ma[i][j]=0;
                else ma[i][j]=1;
            }
        }
        int x,y,dir=0;
        cin>>x>>y;
        x--;
        y--;
        getchar();
        char ram='t';
        while (ram!='Q')
        {
            ram=getchar();
            if (ram=='R')dir++;
            if (ram=='L')dir=dir-1+4;
            if (ram=='F')
            {
                if (dir==0&&ma[x-1][y]==1)x--;
                if (dir==1&&ma[x][y+1]==1)y++;
                if (dir==2&&ma[x+1][y]==1)x++;
                if (dir==3&&ma[x][y-1]==1)y--;
            }
            dir%=4;
        }
        if (fir==1)printf ("\n");
        fir=1;
        printf ("%d %d ",x+1,y+1);
        if (dir==0)printf ("N\n");
        if (dir==1)printf ("E\n");
        if (dir==2)printf ("S\n");
        if (dir==3)printf ("W\n");
    }
}
