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
		int t,h,f;
		cin>>t>>h>>f;
		int tr[t][h+2];
		int ar[t][h+2];
		int dp[h+2];
		for (int i=0;i<h+2;i++)
		{
			dp[i]=0;
			for (int j=0;j<t;j++)
			{
				ar[j][i]=0;
				tr[j][i]=0;
			}
		}
		for (int i=0;i<t;i++)
		{
			int n,a;
			cin>>n;
			for (int j=0;j<n;j++)
			{
				cin>>a;
				tr[i][a]++;
			}
		}
		for (int i=0;i<h+1;i++)
		{
			for (int j=0;j<t;j++)
			{
				if (i>=f)
				{
					ar[j][i]=max(ar[j][i-1],dp[i-f]);
				}
				else if (i>0)
				{
					ar[j][i]=ar[j][i-1];
				}
				ar[j][i]+=tr[j][i];
				dp[i]=max(dp[i],ar[j][i]);
			}
		}
		printf ("%d\n",dp[h]);
	}
}