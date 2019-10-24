//UVA 11517 Exact Change
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int pri;
        cin>>pri;
        int dp[10005];
        for (int i=0;i<10005;i++)
        {
            dp[i]=(1<<29);
        }
        dp[0]=0;
        int n;
        cin>>n;
        int a;
        stack<int>li;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            for (int j=0;j<10005;j++)
            {
                if (j-a>=0&&dp[j-a]<(1<<29))
                {
                    li.push(j);
                }
            }
            while (!li.empty())
            {
                dp[li.top()]=min(dp[li.top()],1+dp[li.top()-a]);
                li.pop();
            }
        }
        for (int i=pri;i<10005;i++)
        {
            if (dp[i]<(1<<29))
            {
                printf ("%d %d\n",i,dp[i]);
                break;
            }
        }
    }
}
