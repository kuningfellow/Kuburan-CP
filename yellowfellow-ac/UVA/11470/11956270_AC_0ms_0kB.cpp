//UVA 11470 Square Sums
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n;
int ar[11][11];
int serc(int a)
{
    int sum=0;
    for (int i=a;i<n-a;i++)
    {
        if (a!=n-a-1)
            sum+=ar[i][a]+ar[i][n-a-1];
        else sum+=ar[i][a];
    }
    for (int i=a+1;i<n-a-1;i++)
    {
        if (a!=n-a-1)
            sum+=ar[a][i]+ar[n-a-1][i];
        else sum+=ar[a][i];
    }
    return sum;
}
int main()
{
    int kas=1;
    while (1<2)
    {
        cin>>n;
        if (n==0)break;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&ar[i][j]);
            }
        }
        int we[n];
        for (int i=0;i<n/2+(n%2>0);i++)
        {
            we[i]=serc(i);
        }
        printf ("Case %d:",kas++);
        for (int i=0;i<n/2+(n%2>0);i++)
        {
            printf (" %d",we[i]);
        }
        printf("\n");
    }
}
