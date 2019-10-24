#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int par[30005];
int co[30005];
int finpar(int x)
{
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n,m;
		cin>>n>>m;
		for (int i=0;i<n;i++)
		{
			par[i]=i;
			co[i]=0;
		}
		int a,b;
		int maxi=0;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			a--;
			b--;
			if (finpar(a)!=finpar(b))
			{
				par[finpar(a)]=finpar(b);
			}
		}
		for (int i=0;i<n;i++)
		{
			co[finpar(i)]++;
			if (co[finpar(i)]>maxi)maxi=co[finpar(i)];
		}
		printf ("%d\n",maxi);
	}
}