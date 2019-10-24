//UVA 10306 e-Coins
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
double dis(int a, int b)
{
    double g=a*a+b*b;
    return sqrt(g);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        double s;
        scanf("%d%lf",&n,&s);
        vector<pair<int,int> >coin;
        int a,b;
        for (int i=0;i<n;i++)
        {
            cin>>a>>b;
            coin.push_back(pair<int,int>(a,b));
        }
        queue<pair<int,int> >q;
        q.push(pair<int,int>(0,0));
        int visit[301][301];
        for (int i=0;i<=s;i++)
        {
            for (int j=0;j<=s;j++)
            {
                visit[i][j]=0;
            }
        }
        int cost=1;
        int ans=-1;
        while (!q.empty())
        {
            int siz=q.size();
            for (int i=0;i<siz;i++)
            {
                for (int j=0;j<n;j++)
                {
                    a=q.front().first;
                    b=q.front().second;
                    if (dis (a+coin[j].first,b+coin[j].second)==s)
                    {
                        ans=cost;
                        break;
                    }
                    else if (dis(a+coin[j].first,b+coin[j].second)<s&&visit[a+coin[j].first][b+coin[j].second]==0)
                    {
                        q.push(pair<int,int>(a+coin[j].first,b+coin[j].second));
                        visit[a+coin[j].first][b+coin[j].second]=1;
                    }
                }
                q.pop();
                if (ans!=-1)break;
            }
            if (ans!=-1)break;
            cost++;
        }
        if (ans==-1)printf ("not possible\n");
        else printf ("%d\n",ans);
    }
}
