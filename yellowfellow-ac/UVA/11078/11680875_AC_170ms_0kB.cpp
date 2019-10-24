//UVA 11078 Open Credit System
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a=-1;
        int ma=0,mi=(1<<31)-1;
        int t[n];
        for (int i=0;i<n;i++)
        {
            cin>>t[i];
        }
        ma=t[0];
        for (int i=0;i<n;i++)
        {
            if (ma>t[i]&&ma-t[i]>a)
            {
                a=ma-t[i];
            }
            else if (t[i]>ma)
            {
                ma=t[i];
            }
        }
        printf ("%d\n",a);
    }
}
