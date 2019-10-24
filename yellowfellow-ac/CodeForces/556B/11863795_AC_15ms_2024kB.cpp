#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    int temp=0;
    temp=(ar[0]+n)%n;
    int yes=1;
    for (int i=1;i<n;i++)
    {
        if (i%2==0)
        {
            if ((ar[i]-i+n)%n!=temp)
            {
                yes=0;
                break;
            }
        }
        else if ((i-ar[i]+n)%n!=temp)
        {
            yes=0;
            break;
        }
    }
    if (yes==0)
    {
        yes=1;
        temp=(n-ar[0])%n;
        for (int i=1;i<n;i++)
        {
            if (i%2==0)
            {
                if ((i-ar[i]+n)%n!=temp)
                {
                    yes=0;
                    break;
                }
            }
            else if ((ar[i]-i+n)%n!=temp)
            {
                yes=0;
                break;
            }
        }
    }
    if (yes==1)printf ("Yes\n");
    else printf ("No\n");
}
