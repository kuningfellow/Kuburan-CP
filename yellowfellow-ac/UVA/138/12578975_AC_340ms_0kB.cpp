#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    long long int m=8;
    long long int n;
    int co=10;
    while (co)
    {
        if ((long long)sqrt(m*(m+1)/2)*(long long)sqrt(m*(m+1)/2)==m*(m+1)/2)
        {
            printf ("%10lld%10lld\n",(long long int)sqrt(m*(m+1)/2),m);
            co--;
        }
        m++;
    }
}