//UVA 12583 Memory Overflow
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    int kas=1;
    cin>>tc;
    while (tc--)
    {
        int n,k;
        cin>>n>>k;
        char nam[n+1];
        scanf("%s",nam);
        int rem=0;
        for (int i=0;i<n;i++)
        {
            for (int j=1;j<=k;j++)
            {
                if (i-j>=0&&nam[i-j]==nam[i])
                {
                    rem++;
                    break;
                }
            }
        }
        printf ("Case %d: %d\n",kas++,rem);
    }
}
