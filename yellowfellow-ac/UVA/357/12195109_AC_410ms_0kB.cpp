//UVA 357 Let Me Count The Ways
#include <stdio.h>
#include <iostream>
using namespace std;
int co[5]={1,5,10,25,50};
long long int dp[30005];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n+1;i++)dp[i]=0;
        dp[0]=1;
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<n+1;j++)
            {
                if (j-co[i]>=0)
                {
                    dp[j]+=dp[j-co[i]];
                }
            }
        }
        long long int way=dp[n];
        if (way==1)
            printf ("There is only 1 way to produce %d cents change.\n",n);
        else
            printf ("There are %lld ways to produce %d cents change.\n",way,n);
    }
}
