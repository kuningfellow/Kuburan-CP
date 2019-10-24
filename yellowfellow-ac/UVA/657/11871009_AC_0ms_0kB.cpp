//UVA 657 The die is cast
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
char ma[55][55];
int me[55][55];
int n,m;
int around(int x, int y)
{
    for (int i=-1;i<2;i++)
    {
        for (int j=-1;j<2;j++)
        {
            if (x+i<m&&x+i>=0&&y+j<n&&y+j>=0)
                if (ma[x+i][y+j]=='*')
                    return 1;
        }
    }
    return 0;
}
void kill(int x, int y)
{
    if (x+1<m&&ma[x+1][y]=='X')
    {
        if (around(x+1,y))
        {
            ma[x+1][y]='*';
            kill(x+1,y);
        }
    }
    if (x-1>=0&&ma[x-1][y]=='X')
    {
        if (around(x-1,y))
        {
            ma[x-1][y]='*';
            kill(x-1,y);
        }
    }
    if (y+1<n&&ma[x][y+1]=='X')
    {
        if (around(x,y+1))
        {
            ma[x][y+1]='*';
            kill(x,y+1);
        }
    }
    if (y-1>=0&&ma[x][y-1]=='X')
    {
        if (around(x,y-1))
        {
            ma[x][y-1]='*';
            kill(x,y-1);
        }
    }
}
void mark(int x, int y,int die)
{
    for (int i=-1;i<2;i++)
    {
        for (int j=-1;j<2;j++)
        {
            if (i+j!=2&&i+j!=-2&&i+j!=0&&x+i<m&&y+j<n&&x+i>=0&&y+j>=0)
            {
                if(ma[x+i][y+j]!='.'&&me[x+i][y+j]==0)
                {
                    me[x+i][y+j]=die;
                    mark(x+i,y+j,die);
                }
            }
        }
    }
}
int main()
{
    int thro=1;
    while (1<2)
    {
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        getchar();
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%c",&ma[i][j]);
            }
            getchar();
        }
        vector<int>coun;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                me[i][j]=0;
        int die=1;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (ma[i][j]!='.'&&me[i][j]==0)
                {
                    me[i][j]=die;
                    mark(i,j,die);
                    die++;
                }
            }
        }
        for (int i=0;i<die+1;i++)
        {
            coun.push_back(0);
        }
        int temp=0;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (ma[i][j]=='X')
                {
                    ma[i][j]='*';
                    kill(i,j);
                    coun[me[i][j]]++;
                }
            }
        }
        for (int i=0;i<coun.size();i++)
        {
            for (int j=0;j<coun.size()-1;j++)
            {
                if (coun[j]>coun[j+1])
                {
                    temp=coun[j];
                    coun[j]=coun[j+1];
                    coun[j+1]=temp;
                }
            }
        }
        printf ("Throw %d\n",thro);
        thro++;
        for (int i=0;i<coun.size();i++)
        {
            if (coun[i]!=0)
            {
                printf ("%d",coun[i]);
                if (i<coun.size()-1)printf (" ");
            }
        }
        printf ("\n");
        printf ("\n");
    }
}
