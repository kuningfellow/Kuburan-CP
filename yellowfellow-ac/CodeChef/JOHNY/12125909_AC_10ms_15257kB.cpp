#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int ar[n];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        int k;
        cin>>k;
        int pos=0;
        for (int i=0;i<n;i++)
        {
            if (ar[i]<ar[k-1])pos++;
        }
        printf ("%d\n",pos+1);
    }
}
