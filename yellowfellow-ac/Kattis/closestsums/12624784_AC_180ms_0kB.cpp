#include <stdio.h>
#include <iostream>
#include <vector>
#define shift 20000000
using namespace std;
bool vis[45000000];
int main()
{
    int kas=1;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ar[n];
        for (int i=0;i<45000000;i++)vis[i]=0;
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                vis[ar[i]+ar[j]+shift]=1;
            }
        }
        int m;
        int a,l,r;
        int ans;
        int found=0;
        printf ("Case %d:\n",kas++);
        cin>>m;
        for (int i=0;i<m;i++)
        {
            cin>>a;
            if (a>=0)
            {
                a+=shift;
                l=a;
                r=a;
                while (l>=0&&r<45000000)
                {
                    if (vis[l]==1)
                    {
                        ans=l;
                        break;
                    }
                    if (vis[r]==1)
                    {
                        ans=r;
                        break;
                    }
                    l--;
                    r++;
                }
            }
            else
            {
                a+=shift;
                l=a;
                r=a;
                while (l>=0&&r<45000000)
                {
                    if (vis[r]==1)
                    {
                        ans=r;
                        break;
                    }
                    if (vis[l]==1)
                    {
                        ans=l;
                        break;
                    }
                    l--;
                    r++;
                }
            }
            printf ("Closest sum to %d is %d.\n",a-shift,ans-shift);
        }
    }
}
