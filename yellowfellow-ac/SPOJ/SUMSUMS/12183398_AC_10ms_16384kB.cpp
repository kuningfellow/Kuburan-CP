#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int bas[2][2];
long long int cur[2][2];
long long int tem[2][2];
long long int m=98765431;
int s;
void mul()
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            tem[i][j]=0;
            for (int k=0;k<2;k++)
            {
                tem[i][j]+=(cur[i][k]*bas[k][j]+m)%m;
                tem[i][j]%=m;
            }
        }
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            bas[i][j]=tem[i][j];
        }
    }
}
void pow()
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            tem[i][j]=0;
            for (int k=0;k<2;k++)
            {
                tem[i][j]+=(cur[i][k]*cur[k][j]+m)%m;
                tem[i][j]%=m;
            }
        }
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            cur[i][j]=tem[i][j];
        }
    }
}
long long int ar[50005];
int main()
{
    int s;
    long long int n;
    cin>>s>>n;
    bas[0][0]=cur[0][0]=-1;
    bas[0][1]=cur[0][1]=1;
    bas[1][0]=cur[1][0]=0;
    bas[1][1]=cur[1][1]=s-1;
    long long int sum=0;
    for (int i=0;i<s;i++)
    {
        scanf("%lld",&ar[i]);
        sum+=ar[i];
        sum%=m;
    }
    if (n==0)
    {
        for (int i=0;i<s;i++)
        {
            printf ("%lld\n",ar[i]%m);
        }
    }
    else
    {
        n--;
        while (n>0)
        {
            if (n%2==1)
            {
                mul();
            }
            pow();
            n/=2;
        }
        if (s==1)
        {
            printf ("0\n");
        }
        else
        {
            for (int i=0;i<s;i++)
            {
                printf ("%lld\n",(bas[0][0]*ar[i]%m+bas[0][1]*sum%m)%m);
            }
        }
    }
}