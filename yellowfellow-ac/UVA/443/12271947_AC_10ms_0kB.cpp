//UVA 443 Humble Numbers
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long int>ef;
int ar[4]={2,3,5,7};
int dp[50][50][50][50];
void serc(int a, int b, int c, int d)
{
    if (a>30||b>30||c>30||d>30||dp[a][b][c][d]==1)return;
    long long int res=1;
    int ta=a;
    while (ta>0)
    {
        res*=2;
        ta--;
    }
    ta=b;
    while (ta>0)
    {
        res*=3;
        ta--;
    }
    ta=c;
    while (ta>0)
    {
        res*=5;
        ta--;
    }
    ta=d;
    while (ta>0)
    {
        res*=7;
        ta--;
    }
    if (res>2000000000)
        return;
    if (res<0)printf ("%d\n",res);
    ef.push_back(res);
    dp[a][b][c][d]=1;
    serc(a+1,b,c,d);
    serc(a,b+1,c,d);
    serc(a,b,c+1,d);
    serc(a,b,c,d+1);
}
int main()
{
    serc(0,0,0,0);
    sort(ef.begin(),ef.end());
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        n--;
        if (n%10==0&&n%100!=10)printf ("The %dst humble number is %d.\n",n+1,ef[n]);
        else if (n%10==1&&n%100!=11)printf ("The %dnd humble number is %d.\n",n+1,ef[n]);
        else if (n%10==2&&n%100!=12)printf ("The %drd humble number is %d.\n",n+1,ef[n]);
        else printf ("The %dth humble number is %d.\n",n+1,ef[n]);
    }
}
