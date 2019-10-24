//UVA 722 Lakes
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char ar[101][101];
int dim=0;
int sid;
int dfs(int x, int y)
{
    int ret=0;
    if (ar[x][y]=='0')
    {
        ret++;
        ar[x][y]='1';
    }
    else if (ar[x][y]!='0')
    {
        return 0;
    }
    if (x+1<dim)ret+=dfs(x+1,y);
    if (y+1<sid)ret+=dfs(x,y+1);
    if (x-1>=0)ret+=dfs(x-1,y);
    if (y-1>=0)ret+=dfs(x,y-1);
    return ret;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        char num[60];
        num[0]='\0';
        while (strlen(num)==0)
        {
            scanf("%[^\n]s",num);
            getchar();
        }
        int i,j;
        i=(num[0]-'0')*10+num[1]-'0';
        j=(num[3]-'0')*10+num[4]-'0';
        char temp[101];
        temp[0]='\0';
        int first=1;
        dim=0;
        while (first==1||strlen(temp)!=0)
        {
            temp[0]='\0';
            scanf("%[^\n]s",temp);
            getchar();
            if (strlen(temp)==0&&first==0)break;
            if (strlen(temp)!=0)
            {
                sid=strlen(temp);
                strcpy(ar[dim++],temp);
                first=0;
            }
        }
        printf ("%d\n",dfs(i-1,j-1));
        if (tc>0)printf ("\n");
    }
}
