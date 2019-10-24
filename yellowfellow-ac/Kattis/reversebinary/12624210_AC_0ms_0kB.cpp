#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[500];
    int i=0;
    while (n>0)
    {
        ar[i]=n%2;
        n/=2;
        i++;
    }
    n=0;
    for (int j=i-1;j>=0;j--)
    {
        n|=(ar[j]<<(i-j-1));
    }
    printf ("%d\n",n);
}
