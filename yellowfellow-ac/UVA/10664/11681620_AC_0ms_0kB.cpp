//UVA 10664 Luggage
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int>suit;
int dp[21][201][201];
int serc(int x, int a, int b)
{
	if (x==suit.size())
	{
		if (a>b)return a-b;
		return b-a;
	}
	if (dp[x][a][b]!=-1)return dp[x][a][b];
	dp[x][a][b]=min(serc(x+1,a+suit[x],b),serc(x+1,a,b+suit[x]));
	return dp[x][a][b];
}
int main()
{
	int t;
	cin>>t;
	getchar();
	while (t--)
	{
		int a=0;
		char c[500];
		scanf("%[^\n]s",c);
		getchar();
		for (int i=0;i<strlen(c);i++)
		{
			if (c[i]>='0'&&c[i]<='9')
			{
				a*=10;
				a+=c[i]-'0';
			}
			else
			{
				suit.push_back(a);
				a=0;
			}
		}
		if (a>0)
			suit.push_back(a);
		for (int i=0;i<suit.size();i++)
		{
			for (int j=0;j<201;j++)
			{
				for (int k=0;k<201;k++)
				{
					dp[i][j][k]=-1;
				}
			}
		}
		if (!serc(0,0,0))printf ("YES\n");
		else printf ("NO\n");
		suit.clear();
	}
}