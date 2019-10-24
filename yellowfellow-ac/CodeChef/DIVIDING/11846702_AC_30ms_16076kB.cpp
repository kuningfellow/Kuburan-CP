#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,sum=0;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }
    if (sum==(n*(n+1)/2))
    {
        printf ("YES\n");
    }
    else printf ("NO\n");
}
