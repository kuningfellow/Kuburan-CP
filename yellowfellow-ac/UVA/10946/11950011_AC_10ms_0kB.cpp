//UVA 10946 You want what filled?
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
char ma[50][50];
int dfs(int i,int j, char c)
{
    int temp=0;
    if (ma[i][j]==c)
    {
        ma[i][j]='.';
        temp=1;
    }
    else return 0;
    if (i+1<n)temp+=dfs(i+1,j,c);
    if (j+1<m)temp+=dfs(i,j+1,c);
    if (i-1>=0)temp+=dfs(i-1,j,c);
    if (j-1>=0)temp+=dfs(i,j-1,c);
    return temp;
}
int main()
{
    int kas=1;
    while (1<2)
    {
        cin>>n>>m;
        if (n==0&&m==0)break;
        for (int i=0;i<n;i++)
        {
            scanf("%s",&ma[i]);
        }
        vector<pair<char,int> >lis;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (ma[i][j]>='A'&&ma[i][j]<='Z')
                {
                    char ce=ma[i][j];
                    lis.push_back(pair<char,int>(ce,dfs(i,j,ma[i][j])));
                }
            }
        }
        for (int i=0;i<lis.size();i++)
        {
            for (int j=0;j<lis.size()-1;j++)
            {
                if (lis[j].second<lis[j+1].second)
                {
                    char y=lis[j].first;
                    int te=lis[j].second;
                    lis[j]=pair<char,int>(lis[j+1].first,lis[j+1].second);
                    lis[j+1]=pair<char,int>(y,te);
                }
                else if (lis[j].second==lis[j+1].second)
                {
                    if (lis[j].first>lis[j+1].first)
                    {
                        char y=lis[j].first;
                        int te=lis[j].second;
                        lis[j]=pair<char,int>(lis[j+1].first,lis[j+1].second);
                        lis[j+1]=pair<char,int>(y,te);
                    }
                }
            }
        }
        printf ("Problem %d:\n",kas++);
        for (int i=0;i<lis.size();i++)
        {
            printf ("%c %d\n",lis[i].first,lis[i].second);
        }
    }
}
