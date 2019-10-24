//UVA 10127 Ones
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int rem=0;
		int m=0;
		int i=1;
		for (;;i++)
		{
			m*=10;
			m++;
			if (m>=n)
			{
				m%=n;
			}
			if (m==0)break;
		}
		printf ("%d\n",i);
	}
}