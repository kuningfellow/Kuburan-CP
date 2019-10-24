#include <stdio.h>
#include <iostream>
using namespace std;
int n,m;
char ma[101][101];
int mar[101][101];
void serc(int x, int y, char a)
{
    for (int i=0;i<n;i++)
    {
        if (ma[i][y]==a&&i!=x)
        {
            mar[i][y]++;
        }
    }
    for (int i=0;i<m;i++)
    {
        if (ma[x][i]==a&&i!=y)
        {
            mar[x][y]++;
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        scanf("%s",ma[i]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            serc(i,j,ma[i][j]);
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mar[i][j]==0)
            {
                printf ("%c",ma[i][j]);
            }
        }
    }
    printf ("\n");
}
