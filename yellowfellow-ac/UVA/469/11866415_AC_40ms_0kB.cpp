//UVA 469 Wetlands of Florida
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
char ma[100][100];
int done[100][100];
int n,m;
int dfs(int x, int y)
{
    int temp=0;
    int cont=1;
    if (done[x][y]==1)cont=0;
    if (ma[x][y]=='W'&&done[x][y]==0)
    {
        done[x][y]=1;
        temp++;
    }
    if (cont==1)
    {
        if (x+1<n&&ma[x+1][y]=='W')temp+=dfs(x+1,y);
        if (x+1<n&&y+1<m&&ma[x+1][y+1]=='W')temp+=dfs(x+1,y+1);
        if (y+1<n&&ma[x][y+1]=='W')temp+=dfs(x,y+1);
        if (x-1>=0&&ma[x-1][y]=='W')temp+=dfs(x-1,y);
        if (x-1>=0&&y-1>=0&&ma[x-1][y-1]=='W')temp+=dfs(x-1,y-1);
        if (x-1>=0&&y+1<m&&ma[x-1][y+1]=='W')temp+=dfs(x-1,y+1);
        if (y-1>=0&&ma[x][y-1]&&ma[x][y-1]=='W')temp+=dfs(x,y-1);
        if (y-1>=0&&x+1<n&&ma[x+1][y-1]=='W')temp+=dfs(x+1,y-1);
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
        m=0;
        int ne=1;
        char temp[100];
        temp[0]='\0';
        while (1<2)
        {
            scanf("%[^\n]",temp);
            getchar();
            if (strlen(temp)==0&&ne==0)break;
            int q[2];
            q[0]=0;
            q[1]=0;
            int si=0;
            if (temp[0]>='0'&&temp[0]<='9')
            {
                ne=0;
                for (int i=0;i<strlen(temp);i++)
                {
                    if (temp[i]>='0'&&temp[i]<='9')
                    {
                        q[si]*=10;
                        q[si]+=temp[i]-'0';
                    }
                    else
                    {
                        si++;
                    }
                }
                for (int i=0;i<n;i++)
                {
                    for (int j=0;j<m;j++)
                    {
                        done[i][j]=0;
                    }
                }
                printf ("%d\n",dfs(q[0]-1,q[1]-1));
            }
            else
            {
                ne=0;
                strcpy(ma[n++],temp);
                m=strlen(temp);
            }
            temp[0]='\0';
        }
        if (tc>0)printf ("\n");
    }
}
