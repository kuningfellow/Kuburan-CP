#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int res[35][35];
long long int pow[35][35];
long long int tem[35][35];
int rel[35][35]={1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
                1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
                0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,
                0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,
                0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,
                0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,
                0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,
                0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,1,0,1,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1};
int match[35]={15,23,39,71,27,43,75,51,83,99,29,45,77,53,85,101,57,89,105,113,30,46,78,54,86,102,58,90,106,114,60,92,108,116,120};
void mul()
{
    for (int i=0;i<35;i++)
    {
        for (int j=0;j<35;j++)
        {
            tem[i][j]=0;
            for (int k=0;k<35;k++)
            {
                tem[i][j]+=pow[i][k]*res[k][j]%1000000007;
                tem[i][j]%=1000000007;
            }
        }
    }
    for (int i=0;i<35;i++)
    {
        for (int j=0;j<35;j++)
        {
            res[i][j]=tem[i][j];
        }
    }
}
void exp()
{
    for (int i=0;i<35;i++)
    {
        for (int j=0;j<35;j++)
        {
            tem[i][j]=0;
            for (int k=0;k<35;k++)
            {
                tem[i][j]+=pow[i][k]*pow[k][j]%1000000007;
                tem[i][j]%=1000000007;
            }
        }
    }
    for (int i=0;i<35;i++)
    {
        for (int j=0;j<35;j++)
        {
            pow[i][j]=tem[i][j];
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        long long int n;
        cin>>n;
        n--;
        int a;
        int fin=0;
        for (int i=0;i<7;i++)
        {
            cin>>a;
            if (a>0)
            {
                fin|=(1<<i);
            }
        }
        if (n==0)
        {
            printf ("1\n");
            continue;
        }
        for (int i=0;i<35;i++)
        {
            if (fin==match[i])
            {
                a=i;
                break;
            }
        }
        for (int i=0;i<35;i++)
        {
            for (int j=0;j<35;j++)
            {
                res[i][j]=pow[i][j]=rel[j][i];
            }
        }
        n--;
        while (n>0)
        {
            if (n%2==1)
            {
                mul();
            }
            exp();
            n/=2;
        }
        long long int ans=0;
        for (int i=0;i<35;i++)
        {
            ans+=res[i][a];
            ans%=1000000007;
        }
        printf ("%lld\n",ans);
    }
}
