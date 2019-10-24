//UVA 725 Division
#include <stdio.h>
using namespace std;
int used[10];
int finduse(int a)
{
	int co=0;
	while (a>0)
	{
		used[a%10]++;
		a/=10;
		co++;
	}
	while (co<5)
	{
		co++;
		used[0]++;
	}
}
int check ()
{
	for (int i=0;i<10;i++)
	{
		if (used[i]!=1)return 0;
	}
	return 1;
}
void reset()
{
	for (int i=0;i<10;i++)
	{
		used[i]=0;
	}
}
int main()
{
	int fir=0;
	while (1<2)
	{
		int n;
		scanf("%d",&n);
		if (n==0)break;
		int fin=0;
		if (fir==1)printf ("\n");
		fir=1;
		for (int i=1234;i<98765;i++)
		{
			int temp=i*n;
			finduse(temp);
			finduse(i);
			if (check())
			{
				fin++;
				printf ("%05d / %05d = %d\n",temp,i,n);
			}
			reset();
		}
		if (fin==0)printf ("There are no solutions for %d.\n",n);
	}
}