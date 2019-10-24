#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int ar[n];
		for (int i=0;i<n;i++)cin>>ar[i];
		int t;
		cin>>t;
		int x=-1,y=-1;
		for (int i=0;i<n-1;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if ((x==-1||max(ar[j]-ar[i],ar[i]-ar[j])<y-x)&&ar[i]+ar[j]==t)
				{
					x=min(ar[i],ar[j]);
					y=max(ar[i],ar[j]);
				}
			}
		}
		printf ("Peter should buy books whose prices are %d and %d.\n\n",x,y);
	}
}