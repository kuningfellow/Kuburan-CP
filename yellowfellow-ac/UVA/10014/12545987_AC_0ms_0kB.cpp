#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc,fir=1;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        double lef;
        double rig;
        cin>>lef;
        cin>>rig;
        double ar[n];
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        double ans=rig+n*(lef);
        for (int i=0;i<n;i++)
        {
            ans-=(n-i)*2*ar[i];
        }
        ans/=(n+1);
        if (fir==0)printf("\n");
        fir=0;
        printf ("%.2f\n",ans);
    }
}
