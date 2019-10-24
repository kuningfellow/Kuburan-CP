//UVA 11743 Credit Check
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		int a=0,b=0,rem,temp;
		for (int i=0;i<4;i++)
		{
			cin>>rem;
			for (int j=0;j<4;j++)
			{
				if (j%2==0)
				{
					b+=rem%10;
				}
				else
				{
					temp=rem%10;
					temp*=2;
					while (temp>0)
					{
						a+=temp%10;
						temp/=10;
					}
				}
				rem/=10;
			}
		}
		a=a+b;
		if (a%10==0)printf ("Valid\n");
		else printf ("Invalid\n");
	}
}