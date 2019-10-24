#include <stdio.h>
int dp[4005];
int a[5];
int temp;
int mas(int n)
{
    if (n<0)
    {
        return -1000000;
    }
    else if (dp[n]!=-1)return dp[n];
    else if (n==0)return 0;
    int i,j;
    int x,y,z;
    x=1+mas(n-a[0]);
    y=1+mas(n-a[1]);
    z=1+mas(n-a[2]);
    temp=x>y?x:y;
    dp[n]=temp>z?temp:z;
    return dp[n];
}
int main()
{
    int n;
    scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
    int i,j;
    for (i=0;i<4005;i++)
        dp[i]=-1;
    for (i=0;i<3;i++)
    {
        for (j=0;j<2;j++)
        {
            if (a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf ("%d",mas(n));
    return 0;
}
