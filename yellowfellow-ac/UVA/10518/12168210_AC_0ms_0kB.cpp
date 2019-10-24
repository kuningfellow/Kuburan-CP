#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int bas[3][3];
long long int cur[3][3];
long long int temp[3][3];
long long int m;
void pow()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            temp[i][j]=0;
            for (int k=0;k<3;k++)
            {
                temp[i][j]+=cur[i][k]*cur[k][j];
                temp[i][j]%=m;
            }
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cur[i][j]=temp[i][j];
        }
    }
}
void mul()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            temp[i][j]=0;
            for (int k=0;k<3;k++)
            {
                temp[i][j]+=cur[i][k]*bas[k][j];
                temp[i][j]%=m;
            }
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            bas[i][j]=temp[i][j];
        }
    }
}
int main()
{
    int kas=1;
    while (1<2)
    {
        long long int n;
        bas[0][0]=cur[0][0]=1;
        bas[0][1]=cur[0][1]=1;
        bas[0][2]=cur[0][2]=1;
        bas[1][0]=cur[1][0]=1;
        bas[1][1]=cur[1][1]=0;
        bas[1][2]=cur[1][2]=0;
        bas[2][0]=cur[2][0]=0;
        bas[2][1]=cur[2][1]=0;
        bas[2][2]=cur[2][2]=1;
        cin>>n>>m;
        if (n==0&&m==0)break;
        if (n<2)printf ("Case %d: %lld %lld %lld\n",kas++,n,m,1%m);
        else if (n==2)printf ("Case %d: %lld %lld %lld\n",kas++,n,m,3%m);
        else
        {
            long long int rem=n;
            n-=3;
            while (n>0)
            {
                if (n%2==1)
                {
                    mul();
                }
                pow();
                n/=2;
            }
            printf ("Case %d: %lld %lld %lld\n",kas++,rem,m,(bas[0][0]*3+bas[0][1]+bas[0][2])%m);
        }
    }
}
