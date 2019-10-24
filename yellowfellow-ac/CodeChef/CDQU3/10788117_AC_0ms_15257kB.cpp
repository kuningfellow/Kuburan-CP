#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while (t>0)
	{
		long long int n;
		scanf("%lld",&n);
		int i;
		int num[32];
		for (i=0;i<32;i++)num[i]=0;
		int index=0;
		int dead,ran=0;
        while(n>1)
        {
			ran=1;
            dead=0;
            for (i=9;i>1;i--)
            {
                if (n%i==0)
                {
                    n/=i;
                    num[index]=i;
                    index++;
                    break;
                }
                else dead++;
            }
            if (dead==8)
            {
                break;
            }
        }
        if (n==1&&ran==0)printf ("11\n");
        else if (dead==8)printf ("-1\n");
        else if (num[1]==0)printf ("1%i\n",num[0]);
        else
		{
			for (i=index-1;i>=0;i--)
			{
				printf ("%i",num[i]);
			}
			printf ("\n");
		}
		t--;
	}
	return 0;
}
