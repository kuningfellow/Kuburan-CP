//UVA 10409 Die Game
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (1<2)
	{
		int show=1;
		int no=2;
		int lef=3;
		int rem;
		char temp[500];
		cin>>n;
		if (n==0)break;
		for (int i=0;i<n;i++)
		{
			scanf("%s",temp);
			if (temp[0]=='n')
			{
				rem=show;
				show=7-no;
				no=rem;
			}
			if (temp[0]=='e')
			{
				rem=show;
				show=lef;
				lef=7-rem;
			}
			if (temp[0]=='s')
			{
				rem=show;
				show=no;
				no=7-rem;
			}
			if (temp[0]=='w')
			{
				rem=show;
				show=7-lef;
				lef=rem;
			}
		}
		printf ("%d\n",show);
	}
}