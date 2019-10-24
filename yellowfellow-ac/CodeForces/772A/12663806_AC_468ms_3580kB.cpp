#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    double p;
    int n;
    cin>>n>>p;
    long long int ar[n][2];
    long long int sum=0;
    long long int bat=0;
    for (int i=0;i<n;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
        sum+=ar[i][0];
        bat+=ar[i][1];
    }
    if (p>=(double)sum)
    {
        printf ("-1\n");
    }
    else
    {
        double l,r,mid,ans;
        double rem,ram;
        l=0;
        r=(double)bat/(sum-p);
        int yes=0;
        for (int i=0;i<100;i++)
        {
            mid=(l+r)/2;
            rem=0;
            yes=1;
            for (int j=0;j<n;j++)
            {
                ram=(ar[j][0]*mid-ar[j][1])/mid;
                if (ram>p-rem)
                {
                    yes=0;
                    break;
                }
                else if (ram>0)
                {
                    rem+=ram;
                }
            }
            if (yes==1)
            {
                ans=mid;
                l=mid;
            }
            else r=mid;
        }
        printf ("%.10f\n",ans);
    }
}
