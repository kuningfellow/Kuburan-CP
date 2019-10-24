//UVA 10279 Mine Sweeper
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
		int n;
		cin>>n;
		char mine[n][n+1];
		for (int i=0;i<n;i++)
		{
			scanf("%s",mine[i]);
		}
		char sel[n][n+1];
		for (int i=0;i<n;i++)
		{
			scanf("%s",sel[i]);
		}
		int out[n][n];
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				out[i][j]=0;
			}
		}
		int show=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (sel[i][j]=='x')
				{
					if (mine[i][j]=='*')
					{
						show=1;
					}
					for (int k=-1;k<=1;k++)
					{
						for (int l=-1;l<=1;l++)
						{
							if (k==0&&l==0)
							{
								continue;
							}
							else if (i+k>=0&&i+k<n&&j+l>=0&&j+l<n)
							{
								if (mine[i+k][j+l]=='*')
								{
									out[i][j]++;
								}
							}
						}
					}
				}
			}
		}
		{
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
				{
					if (show==1&&mine[i][j]=='*')printf ("*");
					else if (sel[i][j]=='x')
					{
						printf ("%d",out[i][j]);
					}
					else printf (".");
				}
				printf ("\n");
			}
		}
		if (tc>0)printf ("\n");
	}
}