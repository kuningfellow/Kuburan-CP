//UVA 11459 Snakes and Ladders
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
		int a,b,c;
		cin>>a>>b>>c;
		int pos[a];
		for (int i=0;i<a;i++)
		{
			pos[i]=1;
		}
		int x,y;
		int snake[101];
		for (int i=0;i<101;i++)
		{
			snake[i]=-1;
		}
		for (int i=0;i<b;i++)
		{
			cin>>x>>y;
			snake[x]=y;
		}
		int done=0;
		int s;
		for (int i=0;i<c;i++)
		{
			cin>>s;
			if (done==0)
			{
				pos[i%a]+=s;
				if (snake[pos[i%a]]!=-1)
				{
					pos[i%a]=snake[pos[i%a]];
				}
				if (pos[i%a]>=100)
				{
					pos[i%a]=100;
					done=1;
				}
			}
		}
		for (int i=0;i<a;i++)
		{
			printf ("Position of player %d is %d.\n",i+1,pos[i]);
		}
	}
}