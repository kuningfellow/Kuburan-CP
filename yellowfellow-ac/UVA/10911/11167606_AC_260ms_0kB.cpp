#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<pair<int,int> >hau5;
double dp[(1<<16)];
int n;
double dis(int a, int b,int x, int y)
{
    a=x-a;
    a=a*a;
    b=b-y;
    b*=b;
    return sqrt(a+b);
}
double serc(int mask)
{
    if (mask==(1<<n)-1)return 0;
    if (dp[mask]<1000000)return dp[mask];
    for (int i=0;i<n;i++)
    {
        if ((mask&(1<<i))>0)continue;
        for (int j=i+1;j<n;j++)
        {
            if ((mask&(1<<j))>0)continue;
            dp[mask]=min(dp[mask],dis(hau5[i].first,hau5[i].second,hau5[j].first,hau5[j].second)+
                         serc((mask|(1<<i))|(1<<j)));
        }
    }
    return dp[mask];
}
int main()
{
    int kase=0;
    while (1<2)
    {
        kase++;
        char shit[50];
        int a,b;
        cin>>n;
        if (n==0)break;
        n*=2;
        for (int i=0;i<n;i++)
        {
            scanf("%s",shit);
            cin>>a>>b;
            hau5.push_back(pair<int,int> (a,b));
        }
        for (int i=0;i<(1<<16);i++)
        {
            dp[i]=1000000;
        }
        hau5.clear();
        printf ("Case %d: %.2f\n",kase,serc(0));
    }
}
