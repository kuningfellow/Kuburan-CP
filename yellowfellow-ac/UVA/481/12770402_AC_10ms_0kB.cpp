//UVA 481 What Goes Up
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int ar[100005];
	int br[100006];
	int cr[100006];
	cr[0]=-1;
	ar[0]=0;
	br[0]=-1;
	int siz=0;
	int l,r,mid,ans;
	int i=1;
	while (scanf("%d",&br[i])!=EOF)
	{
		l=0;
		r=siz;
		ans=(l+r)/2;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (br[ar[mid]]<br[i])
			{
				ans=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		cr[i]=ar[ans];
		ar[ans+1]=i;
		if (ans+1>siz)siz=ans+1;
		i++;
	}
	printf ("%d\n-\n",siz);
	int x=ar[siz];
	vector<int>lis;
	while (x!=-1)
	{
		lis.push_back(br[x]);
		x=cr[x];
	}
	for (int i=lis.size()-2;i>=0;i--)
	{
		printf ("%d\n",lis[i]);
	}
}