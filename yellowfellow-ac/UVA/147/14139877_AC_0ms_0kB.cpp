//UVA 147 Dollars
#include <stdio.h>
long long int dp[30050][12];
long long int chang[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};
long long int sear(int monet,int cap)
{
    if (monet<0)
    {
        return 0;
    }
    if (dp[monet][cap]>0)return dp[monet][cap];
    long long int way=0;
    if (monet==0)
    {
        return 1;
    }
    int i;
    for (i=0;i<11;i++)
    {
        if (chang[i]<=chang[cap])
        {
            way+=sear(monet-chang[i],i);
        }
    }
    dp[monet][cap]=way;
    return dp[monet][cap];
}
int main()
{
    int i;
    while (1<2)
    {
        double money;
        int mona,mano;
        scanf("%d.%d",&mona,&mano);
        if (mona==0&&mano==0)break;
        int monet=mona*100+mano;
        for (i=0;i<11;i++)
        {
            if (chang[i]<=monet)
                break;
        }
        if (i==11)i--;
        money=mona+(double)mano/100;
        printf ("%6.2f%17lld\n",money,sear(monet,i));
    }
    return 0;
}
