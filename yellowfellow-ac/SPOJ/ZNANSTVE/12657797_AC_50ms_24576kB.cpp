#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char ram[n][m+1];
    for (int i=0;i<n;i++)
    {
        scanf("%s",ram[i]);
    }
    long long int rem[n][m];
    for (int i=0;i<m;i++)
    {
        rem[n-1][i]=ram[n-1][i]-'a'+1;
        for (int j=n-2;j>=0;j--)
        {
            rem[j][i]=(long long)rem[j+1][i]*100+(ram[j][i]-'a'+1);
        }
    }
    int l=0;
    int r=n-1;
    int mid;
    int ans;
    int yes;
    while (l<=r)
    {
        yes=1;
        mid=(l+r)/2;
        for (int j=0;j<m-1;j++)
        {
            for (int k=j+1;k<m;k++)
            {
                if (rem[mid][j]==rem[mid][k])
                {
                    yes=0;
                    break;
                }
            }
        }
        if (yes==1)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    printf ("%d\n",ans);
}
