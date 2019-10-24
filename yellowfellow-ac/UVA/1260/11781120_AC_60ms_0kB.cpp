//UVA 1260 Sales
//UVA 1260 Sales
#include <stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		int sum=0;;
		int ar[n];
		for (int i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
		}
		for (int i=n-1;i>=0;i--)
		{
			for (int j=1;j<n;j++)
			{
				if(i<j&&ar[i]<=ar[j])sum++;
			}
		}
		printf ("%d\n",sum);
	}
}