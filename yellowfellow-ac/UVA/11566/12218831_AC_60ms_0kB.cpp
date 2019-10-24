#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int n,x,t,k;
int dim[105][2];
int dp[105][2000][25];
int good(int co)
{
	int monet=co*110/100;
	if ((co*110)%100>0)
	{
		monet++;
	}
	if (monet>(n+1)*x)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int serc(int p, int co, int ta)
{
	if (p==k)
	{
		if (good(co+(n+1)*t)&&ta<=2*(n+1))
		{
			return 0;
		}
		else
		{
			return -1000000000;
		}
	}
	if (dp[p][co][ta]!=-1)
	{
		return dp[p][co][ta];
	}
	int remy=serc(p+1,co,ta);
	int rem=0;
	int ram=0;
	if (good(co+dim[p][0]+(n+1)*t)&&ta+1<=(n+1)*2)
		rem=dim[p][1]+serc(p+1,co+dim[p][0],ta+1);
	if (good(co+2*dim[p][0]+(n+1)*t)&&ta+2<=(n+1)*2)
		ram=2*dim[p][1]+serc(p+1,co+2*dim[p][0],ta+2);
	remy=max(remy,rem);
	remy=max(remy,ram);
	return dp[p][co][ta]=remy;
}
int main()
{
	while (scanf("%d%d%d%d",&n,&x,&t,&k)!=EOF)
	{
		if (n==0&&x==0&&t==0&&k==0)
		{
			break;
		}
		for (int i=0;i<k;i++)
		{
			for (int j=0;j<=x*(n+1);j++)
			{
				for (int q=0;q<=(n+1)*2;q++)
				{
					dp[i][j][q]=-1;
				}
			}
		}
		for (int i=0;i<k;i++)
		{
			int a=0;
			int b;
			scanf("%d",&dim[i][0]);
			for (int j=0;j<=n;j++)
			{
				scanf("%d",&b);
				a+=b;
			}
			dim[i][1]=a;
		}
		printf ("%.2f\n",(double)serc(0,0,0)/(n+1));
	}
}