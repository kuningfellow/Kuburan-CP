#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
double comb(int a, int b)
{
    double ret=1;
    for (int i=b+1;i<=a;i++)
    {
        ret*=i;
    }
    return ret;
}
int main()
{
    int n,k;
    double res;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        res=comb(n,n-k);
        res/=comb(k,1);
        int dig=0;
        while (res>=1)
        {
            dig++;
            res/=10;
        }
        printf ("%d\n",dig);
    }
}
