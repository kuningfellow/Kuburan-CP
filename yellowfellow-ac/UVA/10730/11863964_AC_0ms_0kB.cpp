//UVA 10730 Antiarithmetic?
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    while (1<2)
    {
        int n;
        scanf("%d:",&n);
        if (n==0)break;
        int ar[n];
        int a;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            ar[a]=i;
        }
        int yes=1;
        int done=0;
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (j+j-i<n&&((ar[i]>ar[j]&&ar[j]>ar[j+(j-i)])||(ar[i]<ar[j]&&ar[j]<ar[j+(j-i)])))
                {
                    yes=0;
                    break;
                }
                if (j+j-i>=n)
                {
                    break;
                }
            }
            if (yes==0)break;
        }
        if (yes==0)printf ("no\n");
        else printf ("yes\n");
    }
}
