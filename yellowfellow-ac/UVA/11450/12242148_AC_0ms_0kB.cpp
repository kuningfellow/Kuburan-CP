//UVA 11450 Wedding shopping
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int m,c;
        cin>>m>>c;
        vector<int>ar[c];
        for (int i=0;i<c;i++)
        {
            int n;
            int a;
            cin>>n;
            for (int j=0;j<n;j++)
            {
                cin>>a;
                ar[i].push_back(a);
            }
        }
        int dp[m+1];
        for (int i=0;i<=m;i++)dp[i]=0;
        dp[0]=1;
        for (int i=0;i<c;i++)
        {
            for (int k=0;k<=m;k++)
            {
                for (int j=0;j<ar[i].size();j++)
                {
                    if (k-ar[i][j]>=0&&((dp[k-ar[i][j]])&(1<<(i)))>0)
                    {
                        dp[k]|=(1<<(i+1));
                    }
                }
            }
        }
        int foun=0;
        for (int i=m;i>=0;i--)
        {
            if ((dp[i]&(1<<c))>0)
            {
                printf ("%d\n",i);
                foun=1;
                break;
            }
        }
        if (foun==0)printf ("no solution\n");
    }
}
