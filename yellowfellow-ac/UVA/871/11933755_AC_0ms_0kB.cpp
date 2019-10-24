//UVA 871 Counting Cells in a Blob
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char ar[101][101];
int n,m;
int dfs(int x, int y)
{
    int temp=1;
    if (ar[x][y]!='1')return 0;
    else if (ar[x][y]=='1')
    {
        ar[x][y]='0';
        if (x+1<n)temp+=dfs(x+1,y);
        if (y+1<m)temp+=dfs(x,y+1);
        if (x-1>=0)temp+=dfs(x-1,y);
        if (y-1>=0)temp+=dfs(x,y-1);
        if (x+1<n&&y+1<m)temp+=dfs(x+1,y+1);
        if (x+1<n&&y-1>=0)temp+=dfs(x+1,y-1);
        if (x-1>=0&&y+1<m)temp+=dfs(x-1,y+1);
        if (x-1>=0&&y-1>=0)temp+=dfs(x-1,y-1);
    }
    return temp;
}
int main()
{
    int tc;
    cin>>tc;
    getchar();
    while (tc--)
    {
        n=0;
        char temp[50];
        temp[0]='\0';
        while (strlen(temp)==0)
        {
            temp[0]='\0';
            scanf("%[^\n]s",temp);
            getchar();
        }
        while (strlen(temp)!=0)
        {
            strcpy(ar[n++],temp);
            temp[0]='\0';
            scanf("%[^\n]s",temp);
            getchar();
        }
        m=strlen(ar[0]);
        int maxi=0;
        int tamp;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (ar[i][j]=='1')
                {
                    tamp=dfs(i,j);
                    if (tamp>maxi)maxi=tamp;
                }
            }
        }
        printf ("%d\n",maxi);
        if (tc>0)printf ("\n");
    }
}
