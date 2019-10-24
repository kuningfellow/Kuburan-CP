#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,max=0,a=0,temp,min=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf("%d",&temp);
			if (j==0)
			{
				min=temp;
			}
			else if (temp<min)
			{
				min=temp;
			}
		}
		if (max<min)
		{
			max=min;
			a=i;
		}
	}
	a++;
	printf ("%i",max);
	return 0;
}
