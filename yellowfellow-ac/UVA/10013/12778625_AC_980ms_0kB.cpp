#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int ar[1000005];
int br[1000005];
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n,rem=0;
		cin>>n;
		ar[n]=0;
		for (int i=n-1;i>=0;i--)
		{
			cin>>ar[i]>>br[i];
		}
		for (int i=0;i<n;i++)
		{
			ar[i]+=br[i]+rem;
			rem=ar[i]/10;
			ar[i]%=10;
		}
		if (rem>0)ar[n++]=rem;
		for (int i=n-1;i>=0;i--)
		{
			printf ("%d",ar[i]);
		}
		printf ("\n");
		if (tc!=0)printf ("\n");
	}
}