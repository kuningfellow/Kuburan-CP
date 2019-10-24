#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int T,w;
int n;
int tre[30][2];
pair<int,int> dp[30][1000];
int serc(int x, int t)
{
	if (x==n)return 0;
	if (dp[x][t].first>0)return dp[x][t].first;
	int temp=0;
	if (t-(3*w*tre[x][0])>=0)
		temp=tre[x][1]+serc(x+1,t-(3*w*tre[x][0]));
	int tamp=serc(x+1,t);
	if (temp>tamp)
	{
		dp[x][t]=pair<int,int>(temp,t-(3*w*tre[x][0]));
	}
	else
		dp[x][t]=pair<int,int>(tamp,t);
	return dp[x][t].first;
}
int main()
{
	int kase=0;
	while (scanf("%d%d",&T,&w)!=EOF)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d%d",&tre[i][0],&tre[i][1]);
		}
		if (kase>0)printf ("\n");
		kase=1;
		cout<<serc(0,T)<<endl;
		int curt=T;
		vector<int> picked;
		int coun=0;
		for (int i=0;i<n;i++)
		{
			if (dp[i][curt].second!=curt)
			{
				coun++;
				picked.push_back(i);
				curt=dp[i][curt].second;
			}
		}
		printf ("%d\n",coun);
		for (int i=0;i<picked.size();i++)
		{
			printf ("%d %d\n",tre[picked[i]][0],tre[picked[i]][1]);
		}
		memset (dp,0,sizeof(dp));
	}
}