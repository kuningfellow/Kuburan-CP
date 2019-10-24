#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int check(int a, int b, int c, int d, int e, int f)
{
	if ((a-c)*(a-c)+(b-d)*(b-d)==(a-e)*(a-e)+(b-f)*(b-f)+(e-c)*(e-c)+(f-d)*(f-d))
		return 1;
	return 0;
}
int main()
{
	int tc;
	cin>>tc;
	int co=0;
	while (tc--)
	{
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		if (check(a,b,c,d,e,f)+check(c,d,e,f,a,b)+check(e,f,a,b,c,d)>0)
		{
			co++;
		}
	}
	printf ("%d\n",co);
}