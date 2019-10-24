//UVA 10346 Peter's Smokes
#include <stdio.h>
using namespace std;
int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int cig=n;
        while (n>=k)
        {
            cig+=n/k;
            n=n%k+n/k;
        }
        printf ("%d\n",cig);
    }
}
