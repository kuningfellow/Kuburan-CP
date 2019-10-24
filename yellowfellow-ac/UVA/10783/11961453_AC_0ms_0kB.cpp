//UVA 10783 Odd Sum
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc,kas=1;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        cin>>a>>b;
        if (!(a&1))a++;
        if (!(b&1))b--;
        int n=(b-a)/2+1;
        printf ("Case %d: %d\n",kas++,n*(2*(n-1)+2*a)/2);
    }
}
