//UVA 166 Making Change
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int con[6]={5,10,20,50,100,200};
int near[510][6];
int least[510];
int sercnear(int monet,int cap)
{
    if (monet==0)return 0;
    if (near[monet][cap]>=0)
    near[monet][cap]=1000000;
    for (int i=0;i<cap;i++)
    {
        if (monet-con[i]>=0)
            near[monet][cap]=min(near[monet][cap],1+sercnear(monet-con[i],i+1));
    }
    return near[monet][cap];
}
int price;
int dp[1020][6];
int cun[6];
int can(int a, int x)
{
    if (x==6&&a<price)return 100000;
    if (a>=1000)return 1000000;
    if (dp[a][x]>0)return dp[a][x];
    dp[a][x]=1000000;
    if (a>=price)
    {
        if (least[a-price]>0)
        {
            dp[a][x]=least[a-price];
        }
        else if (a==price)
        {
            dp[a][x]=0;
        }
    }
    if (x<6)
        for (int i=0;i<=cun[x];i++)
            dp[a][x]=min(dp[a][x],i+can(a+i*con[x],x+1));
    return dp[a][x];
}
int main()
{
    for (int i=1;i<=100;i++)
    {
        least[i*5]=sercnear(i*5,6);
    }
    while (1<2)
    {
        cin>>cun[0]>>cun[1]>>cun[2]>>cun[3]>>cun[4]>>cun[5];
        if (cun[0]+cun[1]+cun[2]+cun[3]+cun[4]+cun[5]==0)break;
        int a,b;
        scanf("%d.%d",&a,&b);
        a*=100;
        price=a+b;
        printf ("%3d\n",can(0,0));
        for (int i=0;i<1020;i++)
            for (int j=0;j<6;j++)
                dp[i][j]=0;
    }
}
