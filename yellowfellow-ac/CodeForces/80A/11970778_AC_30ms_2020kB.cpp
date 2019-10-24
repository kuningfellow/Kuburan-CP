#include <stdio.h>
#include <iostream>
using namespace std;

int primes[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main()
{
    int m,n;
    cin>>m>>n;
    int yes=0;
    for (int i=0;i<14;i++)
    {
        if (primes[i]==m&&primes[i+1]==n)
        {
            yes=1;
            printf ("YES\n");
            break;
        }
    }
    if (yes==0)printf ("NO\n");
}
