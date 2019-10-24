#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int h,w;
char ar[501][501];
void serc(int x, int y, char c)
{
    if (ar[x][y]==c)
    {
        ar[x][y]='.';
        if (x+1<h)serc(x+1,y,c);
        if (y+1<w)serc(x,y+1,c);
        if (x-1>=0)serc(x-1,y,c);
        if (y-1>=0)serc(x,y-1,c);
    }
}
int main()
{
    int tc;
    int kas=1;
    cin>>tc;
    while (tc--)
    {
        cin>>h>>w;
        for (int i=0;i<h;i++)
        {
            scanf("%s",ar[i]);
        }
        int lis[26][2];
        for (int i=0;i<26;i++)
        {
            lis[i][0]=0;
            lis[i][1]=i;
        }
        for (int i=0;i<h;i++)
        {
            for (int j=0;j<w;j++)
            {
                if (ar[i][j]!='.')
                {
                    lis[ar[i][j]-'a'][0]++;
                    serc(i,j,ar[i][j]);
                }
            }
        }
        int temp,tempy;
        for (int i=0;i<26;i++)
        {
            for (int j=0;j<25;j++)
            {
                if (lis[j][0]<lis[j+1][0]||(lis[j][0]==lis[j+1][0]&&lis[j][1]>lis[j+1][1]))
                {
                    temp=lis[j][0];
                    tempy=lis[j][1];
                    lis[j][0]=lis[j+1][0];
                    lis[j][1]=lis[j+1][1];
                    lis[j+1][0]=temp;
                    lis[j+1][1]=tempy;
                }
            }
        }
        printf ("World #%d\n",kas++);
        for (int i=0;i<26;i++)
        {
            if (lis[i][0]==0)break;
            printf ("%c: %d\n",lis[i][1]+'a',lis[i][0]);
        }
    }
}
