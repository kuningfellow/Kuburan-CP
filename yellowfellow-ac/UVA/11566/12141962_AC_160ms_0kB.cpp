#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int fav[105];
int price[105];
int dp[105][2000][30];
int n,k;
int money;
int yum (int menu, int monet, int taken)
{
    int mobet=(monet*110)/100;
    if (((monet*110)%100)>0)
        mobet++;
    if (mobet>money)
        return -10000000;
    if (taken>2*n)
        return -10000000;
    if (menu==k)
        return 0;
    if (dp[menu][monet][taken]!=-1)
        return dp[menu][monet][taken];
    dp[menu][monet][taken]=0;
    for (int i=0;i<=2;i++)
    {
        dp[menu][monet][taken]=max(dp[menu][monet][taken],fav[menu]*i+yum(menu+1,monet+price[menu]*i,taken+i));
    }
    return dp[menu][monet][taken];
}
int main()
{
    int pay,tea;
    while (scanf("%d%d%d%d",&n,&pay,&tea,&k)!=EOF)
    {
        if (n==0&&pay==0&&tea==0&&k==0)break;
        n++;
        int baz;
        for (int i=0;i<k;i++)
        {
            cin>>price[i];
            fav[i]=0;
            for (int j=0;j<n;j++)
            {
                cin>>baz;
                fav[i]+=baz;
            }
        }
        money=n*pay;
        for (int i=0;i<105;i++)
        {
            for (int j=0;j<2000;j++)
            {
                for (int z=0;z<30;z++)
                {
                    dp[i][j][z]=-1;
                }
            }
        }

        double ans=(double)yum(0,n*tea,0)/n;
        if (ans<0)ans=0;
        //FILE *fptr;
        //fptr=fopen("cit.txt","a");
        //fprintf (fptr,"%.2f\n",ans);
        printf ("%.2f\n",ans);
    }
}