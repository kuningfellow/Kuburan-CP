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
        int ye=0;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            if (a%2==0&&a!=0)
            {
                co++;
            }
            if (a%2==1)
            {
                ye=1;
            }
        }
        if (k==0&&ye==1)printf ("YES\n");
        else if (k==0)printf ("NO\n");
        else if (co>=k)printf ("YES\n");
        else printf ("NO\n");
    }
}
