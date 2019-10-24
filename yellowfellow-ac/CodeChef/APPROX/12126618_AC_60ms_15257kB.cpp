#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int a=103993;
    int b=33102;
    while (tc--)
    {
        int n;
        cin>>n;
        int temp=a;
        temp%=b;
        temp*=10;
        printf ("3");
        if (n>0)printf (".");
        for (int i=0;i<n;i++)
        {
            printf ("%d",temp/b);
            temp%=b;
            temp*=10;
        }
        printf ("\n");
    }
}
