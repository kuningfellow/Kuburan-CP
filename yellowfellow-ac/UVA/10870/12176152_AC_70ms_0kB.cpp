#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int bas[16][16];
long long int cur[16][16];
long long int tem[16][16];
long long int num[16];
int d;
long long int m;
void mul()
{
    for (int i=0;i<d;i++)
    {
        for (int j=0;j<d;j++)
        {
            tem[i][j]=0;
            for (int k=0;k<d;k++)
            {
                tem[i][j]+=cur[i][k]*bas[k][j];
                tem[i][j]%=m;
            }
        }
    }
    for (int i=0;i<d;i++)
    {
        for (int j=0;j<d;j++)
        {
            bas[i][j]=tem[i][j];
        }
    }
}
void pow()
{
    for (int i=0;i<d;i++)
    {
        for (int j=0;j<d;j++)
        {
            tem[i][j]=0;
            for (int k=0;k<d;k++)
            {
                tem[i][j]+=cur[i][k]*cur[k][j];
                tem[i][j]%=m;
            }
        }
    }
    for (int i=0;i<d;i++)
    {
        for (int j=0;j<d;j++)
        {
            cur[i][j]=tem[i][j];
        }
    }
}
int main()
{
    while (1<2)
    {
        long long int n;
        cin>>d>>n>>m;
        if (d==0&&n==0&&m==0)break;
        for (int i=0;i<d;i++)
        {
            scanf("%lld",&bas[0][i]);
            cur[0][i]=bas[0][i];
        }
        for (int i=0;i<d;i++)
        {
            scanf("%lld",&num[i]);
        }
        for (int i=1;i<d;i++)
        {
            for (int j=0;j<d;j++)
            {
                if (i-1==j)
                {
                    bas[i][j]=1;
                    cur[i][j]=1;
                }
                else
                {
                    bas[i][j]=0;
                    cur[i][j]=0;
                }
            }
        }
        if (n<=d)
        {
            printf ("%lld\n",num[n-1]%m);
        }
        else
        {
            n-=d;
            n--;
            while(n>0)
            {
                if (n%2==1)
                {
                    mul();
                }
                pow();
                n/=2;
            }
            long long int res=0;
            for (int i=0;i<d;i++)
            {
                res+=num[d-i-1]*bas[0][i];
                res%=m;
            }
            printf ("%lld\n",res);
        }
    }
}
