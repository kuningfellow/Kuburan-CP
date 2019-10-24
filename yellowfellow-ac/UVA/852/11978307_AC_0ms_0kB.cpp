//UVA 852 Deciding victory in Go
#include <stdio.h>
#include <iostream>
using namespace std;
char ma[10][10];
int serc(int x, int y, char m)
{
    if (ma[x][y]==m)return 0;
    if (m=='O'&&ma[x][y]=='X')return -1000000;
    if (m=='X'&&ma[x][y]=='O')return -1000000;
    int ret=0;
    if (ma[x][y]=='.')
    {
        ma[x][y]='c';
        ret++;
    }
    else return 0;
    if (x+1<9)ret+=serc(x+1,y,m);
    if (x-1>=0)ret+=serc(x-1,y,m);
    if (y+1<9)ret+=serc(x,y+1,m);
    if (y-1>=0)ret+=serc(x,y-1,m);
    return ret;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        for (int i=0;i<9;i++)
        {
            scanf("%s",ma[i]);
        }
        int white=0;
        int black=0;
        int temp;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if (ma[i][j]=='X')
                {
                    black++;
                    if (i+1<9&&ma[i+1][j]=='.')
                    {
                        temp=serc(i+1,j,'X');
                        if (temp>0)black+=temp;
                    }
                    if (i-1>=0&&ma[i-1][j]=='.')
                    {
                        temp=serc(i-1,j,'X');
                        if (temp>0)black+=temp;
                    }
                    if (j+1<9&&ma[i][j+1]=='.')
                    {
                        temp=serc(i,j+1,'X');
                        if (temp>0)black+=temp;
                    }
                    if (j-1>=0&&ma[i][j-1]=='.')
                    {
                        temp=serc(i,j-1,'X');
                        if (temp>0)black+=temp;
                    }
                }
                if (ma[i][j]=='O')
                {
                    white++;
                    if (i+1<9&&ma[i+1][j]=='.')
                    {
                        temp=serc(i+1,j,'O');
                        if (temp>0)white+=temp;
                    }
                    if (i-1>=0&&ma[i-1][j]=='.')
                    {
                        temp=serc(i-1,j,'O');
                        if (temp>0)white+=temp;
                    }
                    if (j+1<9&&ma[i][j+1]=='.')
                    {
                        temp=serc(i,j+1,'O');
                        if (temp>0)white+=temp;
                    }
                    if (j-1>=0&&ma[i][j-1]=='.')
                    {
                        temp=serc(i,j-1,'O');
                        if (temp>0)white+=temp;
                    }
                }
            }
        }
        printf ("Black %d White %d\n",black,white);
    }
}
