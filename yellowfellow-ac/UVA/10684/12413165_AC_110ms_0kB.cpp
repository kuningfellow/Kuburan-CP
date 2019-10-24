//UVA 10684 The jackpot
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        int sum=0,a;
        int maxi=0;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            if (a>sum+a)
                sum=a;
            else
                sum+=a;
            maxi=max(maxi,sum);
        }
        if (sum<0)printf ("Losing streak.\n");
        else printf ("The maximum winning streak is %d.\n",maxi);
    }
}
