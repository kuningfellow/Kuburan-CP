#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        int ar[100005];
        int co=0;
        for (int i=0;i<100005;i++)
        {
            ar[i]=0;
        }
        int a;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            if (ar[a]==0)co++;
            ar[a]=1;
        }
        printf ("%d\n",co);
    }
}
