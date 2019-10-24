#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int a;
        int ar[100005];
        for (int i=0;i<100005;i++)
            ar[i]=0;
        int cou=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            if (ar[a]==0)cou++;
            ar[a]++;
        }
        printf ("%d\n",cou);
    }
}
