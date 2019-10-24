//UVA 10487 Closest Sums
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int abs(int a,int b)
{
    if (a>b)return a-b;
    return b-a;
}
int main()
{
    int kase=1;
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        vector<int>ar;
        int a;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            ar.push_back(a);
        }
        int m;
        cin>>m;
        printf ("Case %d:\n",kase++);
        for (int i=0;i<m;i++)
        {
            cin>>a;
            int mini=(1<<30)-1;
            int dis,das;
            for (int j=0;j<n-1;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    dis=abs(ar[j]+ar[k],a);
                    das=abs(a,mini);
                    if (dis<das)
                    {
                        mini=ar[j]+ar[k];
                    }
                }
            }
            printf ("Closest sum to %d is %d.\n",a,mini);
        }
    }
}
