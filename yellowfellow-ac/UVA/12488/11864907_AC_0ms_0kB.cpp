//UVA 12488 Start Grid
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    while (1<2)
    {
        int n;
        if (scanf("%d",&n)==EOF)break;
        int ar[n];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        int ir[n];
        int a;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            ir[a]=i;
        }
        int co=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n-1;j++)
            {
                if (ir[ar[j]]>ir[ar[j+1]])
                {
                    a=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=a;
                    co++;
                }
            }
        }
        printf ("%d\n",co);
    }
}
