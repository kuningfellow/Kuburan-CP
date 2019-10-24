#include <stdio.h>
#include <iostream>
using namespace std;
long long int comb(long long int a)
{
    long long int ret=0;
    for (long long int i=1;i<a;i++)
    {
        ret+=i;
    }
    return ret;
}
int main()
{
    long long int n;
    cin>>n;
    long long int a;
    long long int prev;
    long long int co=n;
    long long int le=0;
    for (long long int i=0;i<n;i++)
    {
        cin>>a;
        if (i>0)
        {
            if (prev==a)
            {
                le++;
            }
            else
            {
                if (le>0)
                {
                    le++;
                    co+=comb(le);
                }
                le=0;
            }
        }
        prev=a;
    }
    if (le>0)
    {
        le++;
        co+=comb(le);
        le=0;
    }
    printf ("%lld\n",co);
}
