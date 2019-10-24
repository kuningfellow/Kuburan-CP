//UVA 1587 Box
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main()
{
	while (1<2)
	{
		int done=0;
		int ar[6][2];
		for (int i=0;i<6;i++)
		{
			if (scanf("%d%d\n",&ar[i][0],&ar[i][1])==EOF)
			{
				done=1;
				break;
			}
		}
		if (done==1)break;
		int side[6];
		int sav[3][2];
		int siz=0;
		for (int i=0;i<6;i++)
		{
			side[i]=0;
		}
		for (int i=0;i<6;i++)
		{
			for (int j=0;j<6;j++)
			{
				if (side[i]==0&&side[j]==0&&i!=j&&((ar[i][0]==ar[j][0]&&ar[i][1]==ar[j][1])||(ar[i][0]==ar[j][1]&&ar[i][1]==ar[j][0])))
				{
					side[i]=1;
					side[j]=1;
					sav[siz][0]=ar[i][0];
					sav[siz][1]=ar[i][1];
					siz++;
				}
			}
		}
		int good=1;
		if (siz!=3)good=0;
		if (good==0)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			good=1;
			int mat[3][3];
			for (int i=0;i<3;i++)
			{
				for (int j=0;j<3;j++)
				{
					mat[i][j]=0;
				}
			}
			int arra[10005];
			for (int i=0;i<10005;i++)arra[i]=0;
			for (int i=0;i<3;i++)
			{
				arra[sav[i][0]]++;
				arra[sav[i][1]]++;
			}
			for (int i=0;i<10005;i++)
			{
				if (arra[i]%2==1)
				{
					good=0;
					break;
				}
			}
			if (good==1)printf ("POSSIBLE\n");
			else printf ("IMPOSSIBLE\n");
		}
	}
}