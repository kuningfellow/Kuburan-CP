//UVA 10004 Bicoloring
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        int l;
        cin>>l;
        n++;
        int ar[n][n];
        int visit[n];
        for (int i=0;i<n;i++)
        {
            visit[i]=0;
            for (int j=0;j<n;j++)
            {
                ar[i][j]=0;
            }
        }
        int a,b;
        for (int i=0;i<l;i++)
        {
            cin>>a>>b;
            ar[a][b]=1;
            ar[b][a]=1;
        }
        queue<int>q;
        q.push(0);
        int siz;
        int col=2;
        visit[q.front()]=1;
        int no=0;
        while (!q.empty())
        {
            siz=q.size();
            for (int i=0;i<siz;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (ar[q.front()][j]==1&&visit[j]!=0)
                    {
                        if (visit[q.front()]==visit[j])
                        {
                            no=1;
                        }
                    }
                    else if (ar[q.front()][j]==1&&visit[j]==0)
                    {
                        visit[j]=col;
                        q.push(j);
                    }
                }
                if (no==1)break;
                q.pop();
            }
            if (no==1)break;
            if (col==1)col=2;
            else if (col==2)col=1;
        }
        if (no==0)printf ("BICOLORABLE.\n");
        else printf ("NOT BICOLORABLE.\n");
    }
}
