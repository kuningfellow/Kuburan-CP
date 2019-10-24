//UVA 357 let Me Count The Ways
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
const int coins [5]={1,5,10,25,50};
int monet;
long long int dp[30001][5];
long long int serc(int x,int n)
{
	if (x==monet)return 1;
	else if (x>monet)return 0;
	if (dp[x][n]!=-1)return dp[x][n];
	dp[x][n]=0;
	for (int i=0;i<5;i++)
	{
		if (i<=n)
		{
			dp[x][n]+=serc(x+coins[i],i);
		}
	}
	return dp[x][n];
}
int main()
{
	while (scanf("%d",&monet)!=EOF)
	{
		for (int i=0;i<monet;i++)
		{
			for (int j=0;j<5;j++)
			{
				dp[i][j]=-1;
			}
		}
		long long int a=serc(0,4);
		if (a==1)printf ("There is only 1 way to produce %d cents change.\n",monet);
		else printf ("There are %lld ways to produce %d cents change.\n",a,monet);
	}
}
