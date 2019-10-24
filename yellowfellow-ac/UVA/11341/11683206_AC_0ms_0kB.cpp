//UVA 11341 Term Strategy
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
int ar[11][101];
int dp[11][101];
int serc(int x, int d)
{
	if (x==n)return 0;
	if (dp[x][d]>0)return dp[x][d];
	dp[x][d]=-(1<<30);
	for (int i=0;i<m;i++)
	{
		if (ar[x][i]>4&&d+i+1<=m)
			dp[x][d]=max(dp[x][d],ar[x][i]+serc(x+1,d+i+1));
	}
	return dp[x][d];
}
int main()
{
	FILE *kon;
	kon=fopen("debuk.txt","w");
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				cin>>ar[i][j];	
			}
		}
		int a=serc(0,0);
		if ((double)a/n<5)printf ("Peter, you shouldn't have played billiard that much.\n");
		else printf ("Maximal possible average mark - %.2f.\n",(1e-9 + a)/n);
		for (int i=0;i<11;i++)
		{
			for (int j=0;j<101;j++)
			{
				dp[i][j]=0;
			}
		}
	}
}