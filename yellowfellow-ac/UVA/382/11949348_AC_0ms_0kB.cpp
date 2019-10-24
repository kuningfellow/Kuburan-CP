//UVA 382 Perfection
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    printf ("PERFECTION OUTPUT\n");
    while (1<2)
    {
        scanf("%d",&n);
        if (n==0)break;
        int temp=0;
        for (int i=1;i<n;i++)
        {
            if (n%i==0)
            {
                temp+=i;
            }
        }
        if (temp>n)
        {
            printf ("%5d  ABUNDANT\n",n);
        }
        else if (temp<n)
        {
            printf ("%5d  DEFICIENT\n",n);
        }
        else if (temp==n)
        {
            printf ("%5d  PERFECT\n",n);
        }
    }
    printf ("END OF OUTPUT\n");
}
