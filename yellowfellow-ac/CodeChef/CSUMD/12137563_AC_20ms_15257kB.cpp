#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long long int bas[2][2];
long long int res[2][2];
long long int mat[2][2];
long long int temp[2][2];
int init()
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            mat[i][j]=bas[i][j];
            res[i][j]=bas[i][j];
        }
    }
}
int pow()
{
    temp[0][0]=mat[0][0]*mat[0][0]+mat[0][1]*mat[1][0];
    temp[0][1]=mat[0][0]*mat[0][1]+mat[0][1]*mat[1][1];
    temp[1][0]=mat[1][0]*mat[0][0]+mat[1][1]*mat[1][0];
    temp[1][1]=mat[1][0]*mat[0][1]+mat[1][1]*mat[1][1];
    mat[0][0]=temp[0][0]%1000000007;
    mat[0][1]=temp[0][1]%1000000007;
    mat[1][0]=temp[1][0]%1000000007;
    mat[1][1]=temp[1][1]%1000000007;
}
int mul()
{
    temp[0][0]=mat[0][0]*res[0][0]+mat[0][1]*res[1][0];
    temp[0][1]=mat[0][0]*res[0][1]+mat[0][1]*res[1][1];
    temp[1][0]=mat[1][0]*res[0][0]+mat[1][1]*res[1][0];
    temp[1][1]=mat[1][0]*res[0][1]+mat[1][1]*res[1][1];
    res[0][0]=temp[0][0]%1000000007;
    res[0][1]=temp[0][1]%1000000007;
    res[1][0]=temp[1][0]%1000000007;
    res[1][1]=temp[1][1]%1000000007;
}
int fin(int n)
{
    init();
    while (n>0)
    {
        if(n%2==1)
        {
            mul();
        }
        n/=2;
        pow();
    }
}
int main()
{
    bas[0][0]=2;
    bas[0][1]=2;
    bas[1][0]=1;
    bas[1][1]=0;
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        long long int way=0;
        if (n-1>1)
        {
            fin(n-3);
            way+=(res[0][0]*2+res[0][1])%1000000007;
        }
        else
        {
            way+=n;
        }
        if (n-2>1)
        {
            fin(n-4);
            way+=(res[0][0]*2+res[0][1])%1000000007;
        }
        else
        {
            way+=n-1;
        }
        printf ("%lld\n",way%1000000007);
    }
}
