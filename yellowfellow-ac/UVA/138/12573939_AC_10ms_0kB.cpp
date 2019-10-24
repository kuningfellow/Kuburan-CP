#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    long long int m=8;
    long long int n;
    int co=8;
    while (co)
    {
        if ((long long)sqrt(m*(m+1)/2)*(long long)sqrt(m*(m+1)/2)==m*(m+1)/2)
        {
            printf ("%10lld%10lld\n",(long long int)sqrt(m*(m+1)/2),m);
            co--;
        }
        m++;
    }
    long long int a=7997214;
    long long int b=11309768;
    long long int c=46611179;
    long long int d=65918161;
    printf ("%10lld%10lld\n",a,b);
    printf ("%10lld%10lld\n",c,d);
}
