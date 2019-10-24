//UVA 10370 Above Average
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,co=0;
        cin>>n;
        int ar[n];
        int sum=0;
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        sum/=n;
        for (int i=0;i<n;i++)
        {
            if (ar[i]>sum)co++;
        }
        printf ("%.3f%%\n",(double)co/n*100);
    }
}
