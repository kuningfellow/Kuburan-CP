//UVA 11703 sqrt log sin
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int dp[1000005];
int main()
{
    dp[0]=1;
    for (int a=1;a<=1000000;a++)
    {
        dp[a]=(dp[(int)(a-sqrt(a))]+dp[(int)log(a)]+dp[(int)(a*sin(a)*sin(a))])%1000000;
    }
    int n;
    while (1<2)
    {
        cin>>n;
        if (n==-1)break;
        printf ("%d\n",dp[n]);
    }
}
