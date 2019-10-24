//UVA 706 LC-Display
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	while (1<2)
	{
		int n;
		char in[500];
		cin>>n;
		if (n==0)
			break;
		scanf("%s",in);
		int l=strlen(in);
		for (int i=0;i<l;i++)
		{
			char lis[500]="02356789";
			int done=0;
			for (int j=0;j<8;j++)
			{
				if (in[i]==lis[j])
				{
					done=1;
					break;
				}
			}
			if (done==0)
			{
				for (int j=0;j<n+2;j++)
					printf (" ");
			}
			else
			{
				printf (" ");
				for (int j=0;j<n;j++)
				{
					printf ("-");
				}
				printf (" ");
			}
			if (i<l-1)printf (" ");
		}
		printf ("\n");
		for (int k=0;k<n;k++)
		{
			for (int i=0;i<l;i++)
			{
				char lis[500]="1237";
				int done=0;
				for (int j=0;j<4;j++)
				{
					if (in[i]==lis[j])
					{
						done=1;
						break;
					}
				}
				if (done==0)
				{
					if (in[i]=='5'||in[i]=='6')
					{
						done=2;
					}
				}
				if (done==0)done=3;
				if (done==1)
				{
					for (int j=0;j<n+1;j++)
						printf (" ");
					printf ("|");
				}
				if (done==2)
				{
					printf ("|");
					for (int j=0;j<n+1;j++)
						printf (" ");
				}
				if (done==3)
				{
					printf ("|");
					for (int j=0;j<n;j++)
						printf (" ");
					printf ("|");
				}
				if (i<l-1)printf (" ");
			}
			printf ("\n");
		}
		for (int i=0;i<l;i++)
		{
			if (in[i]=='7'||in[i]=='1'||in[i]=='0')
			{
				for (int j=0;j<n+2;j++)
					printf (" ");
			}
			else
			{
				printf (" ");
				for (int j=0;j<n;j++)
					printf ("-");
				printf (" ");
			}
			if (i<l-1)printf (" ");
		}
		printf ("\n");
		for (int k=0;k<n;k++)
		{
			for (int i=0;i<l;i++)
			{
				char lis[500]="134579";
				int done=0;
				for (int j=0;j<6;j++)
				{
					if (in[i]==lis[j])
					{
						done=1;
						break;
					}
				}
				if (done==0)
				{
					if (in[i]=='2')
					{
						done=2;
					}
				}
				if (done==0)done=3;
				if (done==1)
				{
					for (int j=0;j<n+1;j++)
						printf (" ");
					printf ("|");
				}
				if (done==2)
				{
					printf ("|");
					for (int j=0;j<n+1;j++)
						printf (" ");
				}
				if (done==3)
				{
					printf ("|");
					for (int j=0;j<n;j++)
						printf (" ");
					printf ("|");
				}
				if (i<l-1)printf (" ");
			}
			printf ("\n");
		}
		for (int i=0;i<l;i++)
		{
			if (in[i]=='1'||in[i]=='4'||in[i]=='7')
			{
				for (int j=0;j<n+2;j++)
					printf (" ");
			}
			else
			{
				printf (" ");
				for (int j=0;j<n;j++)
					printf ("-");
				printf (" ");
			}
			if (i<l-1)printf (" ");
		}
		printf ("\n\n");
	}
}