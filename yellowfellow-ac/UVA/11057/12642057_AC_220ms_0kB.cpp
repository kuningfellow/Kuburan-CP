#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ar[n];
        int del=(1<<30);
        int x,y;
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        int m;
        cin>>m;
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (ar[i]+ar[j]==m&&max(ar[i]-ar[j],ar[j]-ar[i])<del)
                {
                    x=min(ar[i],ar[j]);
                    y=max(ar[j],ar[i]);
                    del=max(ar[i]-ar[j],ar[j]-ar[i]);
                }
            }
        }
        printf ("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
}
