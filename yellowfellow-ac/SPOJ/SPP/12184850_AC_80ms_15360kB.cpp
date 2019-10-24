#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int bas[16][16];
long long int cur[16][16];
long long int tem[16][16];
long long int B[16];
long long int C[16];
int d;
long long int p;
void mul()
{
	for (int i=0;i<=d;i++)
	{
		for (int j=0;j<=d;j++)
		{
			tem[i][j]=0;
			for (int k=0;k<=d;k++)
			{
				tem[i][j]+=cur[i][k]*bas[k][j];
				tem[i][j]%=p;
			}
		}
	}
	for (int i=0;i<=d;i++)
	{
		for (int j=0;j<=d;j++)
		{
			bas[i][j]=tem[i][j];
		}
	}
}
void pow()
{
	for (int i=0;i<=d;i++)
	{
		for (int j=0;j<=d;j++)
		{
			tem[i][j]=0;
			for (int k=0;k<=d;k++)
			{
				tem[i][j]+=cur[i][k]*cur[k][j];
				tem[i][j]%=p;
			}
		}
	}
	for (int i=0;i<=d;i++)
	{
		for (int j=0;j<=d;j++)
		{
			cur[i][j]=tem[i][j];
		}
	}
}
void reset()
{
	for (int i=0;i<d;i++)
	{
		bas[0][i]=cur[0][i]=C[i];
	}
	bas[0][d]=cur[0][d]=0;
	for (int i=1;i<d;i++)
	{
		for (int j=0;j<=d;j++)
		{
			if (i-1==j) bas[i][j]=cur[i][j]=1;
			else bas[i][j]=cur[i][j]=0;
		}
	}
	for (int i=0;i<=d;i++)
	{
		bas[d][i]=cur[d][i]=0;
	}
	bas[d][0]=cur[d][0]=1;
	bas[d][d]=cur[d][d]=1;
}
int main()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>d;
		for (int i=0;i<d;i++)
		{
			scanf("%lld",&B[i]);
		}
		for (int i=0;i<d;i++)
		{
			scanf("%lld",&C[i]);
		}
		long long int l,r;
		long long int bac=0;
		long long int res1=0;
		long long int res2=0;
		cin>>l>>r;
		cin>>p;
		for (int i=0;i<d-1;i++)
		{
			bac+=B[i];
			bac%=p;
		}
		l--;
		if (l<=d)
		{
			for (int i=0;i<l;i++)
			{
				res1+=B[i];
				res1%=p;
			}
		}
		else
		{
			l-=d;
			reset();
			while (l>0)
			{
				if (l%2==1)
				{
					mul();
				}
				pow();
				l/=2;
			}
			for (int i=0;i<d;i++)
			{
				res1+=bas[d][i]*B[d-i-1];
				res1%=p;
			}
			res1+=bas[d][d]*bac;
			res1%=p;
		}
		if (r<=d)
		{
			for (int i=0;i<r;i++)
			{
				res2+=B[i];
				res2%=p;
			}
		}
		else
		{
			r-=d;
			reset();
			while (r>0)
			{
				if (r%2==1)
				{
					mul();
				}
				pow();
				r/=2;
			}
			for (int i=0;i<d;i++)
			{
				res2+=bas[d][i]*B[d-i-1];
				res2%=p;
			}
			res2+=bas[d][d]*bac;
			res2%=p;
		}
		printf ("%lld\n",(res2-res1+p)%p);
	}
}
