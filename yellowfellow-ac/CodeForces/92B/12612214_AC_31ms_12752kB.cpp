#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char ram[1000005];
	bool rem[10000005];
	scanf("%s",ram);
	long long int ans=0;
	int l=strlen(ram);
	int r=0;
	for (int i=0;i<l;i++)
	{
		rem[i]=ram[l-i-1]-'0';
		if (rem[i]==1)r=i;
	}
	l=0;
	while (l<r)
	{
		while (rem[l]==0&&l<r)
		{
			ans++;
			l++;
		}
		if (l==r)break;
		if (rem[l]==1)
		{
			ans++;
			while (l<r&&rem[l]==1)
			{
				ans++;
				l++;
			}
			rem[l]=1;
			if (l==r)
			{
				ans++;
			}
		}
	}
	printf ("%lld\n",ans);
}