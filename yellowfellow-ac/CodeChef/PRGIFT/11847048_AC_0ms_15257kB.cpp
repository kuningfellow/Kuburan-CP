#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,k;
        cin>>n>>k;
        int co=0,a;
        int ar[n];
        for (int i=0;i<n;i++)
        {
            cin>>a;
            ar[i]=a;
        }
        int yay=0;
        for (int i=0;i<n;i++)
        {
            co=0;
            for (int j=i;j<n;j++)
            {
                if (ar[j]%2==0&&ar[j]!=0)
                {
                    co++;
                }
                if (co==k)
                {
                    yay=1;
                    break;
                }
            }
            if (yay==1)break;
        }
        if (yay==1)printf ("YES\n");
        else printf ("NO\n");
    }
}
