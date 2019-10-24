//UVA 11658 Best Coalition
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n,pos;
vector<double>ppl;
double dp[101][100][100];
double serc(int x, double cent)
{
	if (cent+ppl[pos]>50)return ppl[pos]/(cent+ppl[pos]);
	if (x==n)return 0;
	int a=cent;
	a%=100;
	int b=cent*1000;
	b%=10;
	if (b>=5)
	{
		b=(cent*100+1);
	}
	else b=(cent*100);
	b%=100;
	if (dp[x][a][b]!=-1)return dp[x][a][b];
	double temp;
	if (x!=pos)
		temp=max(serc(x+1,cent),serc(x+1,cent+ppl[x]));
	else temp=serc(x+1,cent);
	return dp[x][a][b]=temp;
}
int main()
{
	while (1<2)
	{
		double a;
		cin>>n>>pos;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<100;j++)
			{
				for (int k=0;k<100;k++)
				{
					dp[i][j][k]=-1;
				}
			}
		}
		if (n==0&&pos==0)break;
		for (int i=0;i<n;i++)
		{
			cin>>a;
			ppl.push_back(a);
		}
		pos--;
		printf ("%.2f\n",100*serc(0,0));
		ppl.clear();
	}
}