#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
char rem[500];
int slump(int m,int l)
{
	int yes=1;
	if (l-m<3)return 0;
	if ((rem[m]!='E'&&rem[m]!='D')||rem[l-1]!='G'||rem[m+1]!='F')
	{
		return 0;
	}
	int x=m+1;
	while (x<l-1&&rem[x]=='F')
	{
		x++;
	}
	if (x<l-1)
	{
		return slump(x,l);
	}
	else return 1;
}
int slimp(int left, int right)
{
	if (right-left==2&&rem[left]=='A'&&rem[right-1]=='H')return 1;
	else if (right-left==2)return 0;
	if (rem[right-1]!='C')return 0;
	if (rem[left+1]=='B')return slimp(left+2,right-1);
	return slump(left+1,right-1);
}
int main()
{
	int tc;
	cin>>tc;
	printf ("SLURPYS OUTPUT\n");
	while (tc--)
	{
		scanf("%s",rem);
		int l=strlen(rem);
		int t;
		int yes=0;
		for (int i=l-2;i>=0;i--)
		{
			if (slump(i,l))
			{
				yes=1;
				t=i;
			}
		}
		if (yes==1&&slimp(0,t))
		{
			printf ("YES\n");
		}
		else printf ("NO\n");
	}
	printf ("END OF OUTPUT\n");
}
