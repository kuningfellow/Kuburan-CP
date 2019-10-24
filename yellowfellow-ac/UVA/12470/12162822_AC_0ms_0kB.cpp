#include <stdio.h>
#include <iostream>
using namespace std;
long long int bas[3][3];
long long int cur[3][3];
long long int temp[3][3];
void mul()
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			temp[i][j]=0;
			for (int k=0;k<3;k++)
			{
				temp[i][j]+=cur[i][k]*bas[k][j];
				temp[i][j]%=1000000009;
			}
		}
	}
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			bas[i][j]=temp[i][j];
		}
	}
}
void pow()
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			temp[i][j]=0;
			for (int k=0;k<3;k++)
			{
				temp[i][j]+=cur[i][k]*cur[k][j];
				temp[i][j]%=1000000009;
			}
		}
	}
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cur[i][j]=temp[i][j];
		}
	}
}
int main()
{
	while (1<2)
	{
		long long int n;
		cin>>n;
		if (n==0)break;
		bas[0][0]=cur[0][0]=1;
		bas[0][1]=cur[0][1]=1;
		bas[0][2]=cur[0][2]=1;
		bas[1][0]=cur[1][0]=1;
		bas[1][1]=cur[1][1]=0;
		bas[1][2]=cur[1][2]=0;
		bas[2][0]=cur[2][0]=0;
		bas[2][1]=cur[2][1]=1;
		bas[2][2]=cur[2][2]=0;
		if (n==1)printf ("0\n");
		else if (n==2)printf ("1\n");
		else if (n==3)printf ("2\n");
		else
		{
			n-=4;
			while (n>0)
			{
				if (n%2==1)
				{
					mul();
				}
				pow();
				n/=2;
			}
			printf ("%lld\n",(bas[0][0]*2+bas[0][1])%1000000009);
		}
	}
}