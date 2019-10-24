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
        if (n<3)break;
        long long int way=0;
        for (long long int i=n-2;i>=0;i-=2)
        {
            way+=(i*(i-1)/2);
        }
        printf ("%lld\n",way);
    }
}
