//UVA 10530 Guessing Game
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	char rem[500];
	char ram[500];
	int num;
	int fil[10];
	for (int i=0;i<10;i++)
	{
		fil[i]=0;
	}
	int good=1;
	while (1<2)
	{
		cin>>num;
		if (num==0)break;
		num--;
		scanf("%s",rem);
		scanf("%s",ram);
		if (rem[0]=='r')
		{
			if (fil[num]!=0)
			{
				good=0;
			}
			for (int i=0;i<10;i++)
			{
				if (i<num&&fil[i]==1)
				{
					good=0;
				}
				if (i>num&&fil[i]==-1)
				{
					good=0;
				}
			}
			if (good==1)
			{
				printf ("Stan may be honest\n");
			}
			else
			{
				printf ("Stan is dishonest\n");
			}
			good=1;
			for (int i=0;i<10;i++)
			{
				fil[i]=0;
			}
		}
		else
		{
			if (ram[0]=='h')
			{
				if (fil[num]==-1)good=0;
				fil[num]=1;
			}
			else
			{
				if (fil[num]==1)good=0;
				fil[num]=-1;
			}
		}
	}
}