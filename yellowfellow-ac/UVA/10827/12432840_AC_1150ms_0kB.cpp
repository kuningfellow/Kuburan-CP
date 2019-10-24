//UVA 10827 Maximum sum on a torus
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int sum[n][2*n+1];
        int ar[n][n*2];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cin>>ar[i][j];
                ar[i][j+n]=ar[i][j];
            }
        }
        int rem,ram;
        for (int i=0;i<n;i++)
        {
            sum[i][0]=0;
            rem=0;
            for (int j=0;j<n*2;j++)
            {
                rem+=ar[i][j];
                sum[i][j+1]=rem;
            }
        }
        rem=-(1<<30);
        for (int i=0;i<n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                for (int l=0;l<n;l++)
                {
                    ram=0;
                    for (int k=0;k<n;k++)
                    {
                        ram=max(ram+sum[(l+k)%n][i+j]-sum[(l+k)%n][i],sum[(l+k)%n][i+j]-sum[(l+k)%n][i]);
                        rem=max(rem,ram);
                    }
                }
            }
        }
        printf ("%d\n",rem);
    }
}
