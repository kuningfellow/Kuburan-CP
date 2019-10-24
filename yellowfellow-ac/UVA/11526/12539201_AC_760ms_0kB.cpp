#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        long long int n;
        cin>>n;
        long long int sum=0;
        long long int k=n;
        while (k>0)
        {
            sum+=k*((n/k)-n/(k+1));
            k=n/(n/k+1);
        }
        printf ("%lld\n",sum);
    }
}
