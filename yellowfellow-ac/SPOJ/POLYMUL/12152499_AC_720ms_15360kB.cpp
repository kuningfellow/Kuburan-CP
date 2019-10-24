#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        long long int pol[n*2+1];
        int ar[n+1];
        int br[n+1];
        for (int i=0;i<n*2+1;i++)pol[i]=0;
        for (int i=n;i>=0;i--)
        {
            cin>>ar[i];
        }
        for (int i=n;i>=0;i--)
        {
            cin>>br[i];
        }
        for (int i=0;i<n+1;i++)
        {
            for (int j=0;j<n+1;j++)
            {
                pol[i+j]+=ar[i]*br[j];
            }
        }
        for (int i=n*2;i>=0;i--)
        {
            printf ("%lld",pol[i]);
            if (i>0)printf (" ");
            else printf ("\n");
        }
    }
}
