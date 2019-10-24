#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int abs(int a, int b)
{
}
int main()
{
    int tc;
    int kas=1;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int ar[n];
        int in=1;
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
            if (i>0)
            {
                if (ar[i]-ar[i-1]<-1||ar[i]-ar[i-1]>1)
                {
                    in=0;
                }
            }
        }
        if (in==1)
        {
            printf ("YES\n");
            continue;
        }
        sort(ar,ar+n);
        int yes=1;
        for (int i=0;i<n-1;i++)
        {
            if (ar[i]-ar[i+1]<-1||ar[i]-ar[i+1]>1)
            {
                yes=0;
                break;
            }
        }
        if (yes==0)
            printf("NO\n");
        else printf ("YES\n");
    }
}
