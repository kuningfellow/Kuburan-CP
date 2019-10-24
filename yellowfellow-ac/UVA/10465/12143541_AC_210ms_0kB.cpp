#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int m,n,t;
pair<int,int> dp[10005];
pair<int,int> serc(int time, int bur)
{
    if (time<0)
    {
        return pair<int,int>(time+bur,-1);
    }
    if(time==0)
    {
        return pair<int, int> (0, 0);
    }
    if (dp[time].first!=-1&&dp[time].second!=-1)
    {
        return dp[time];
    }
    pair<int,int>et;
    pair<int,int>it;
    et=pair<int,int>(10005,0);
    it=pair<int,int>(10005,0);
    et=serc(time-n,n);
    et.second++;
    it=serc(time-m,m);
    it.second++;
    if (et.first>it.first)return dp[time]=it;
    else if (et.first<it.first)return dp[time]=et;
    else if (et.second<it.second)return dp[time]=it;
    else return dp[time]=et;
}
int main()
{
    while (scanf("%d%d%d",&m,&n,&t)!=EOF)
    {
        for (int i=0;i<=t;i++)
        {
            dp[i]=pair<int,int>(-1,-1);
        }
        pair<int,int>ret=serc(t,0);
        printf ("%d",ret.second);
        if (ret.first>0)printf (" %d",ret.first);
        printf ("\n");
    }
}
