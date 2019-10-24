#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while (scanf("%d",&n)!=EOF){
        cin>>k;
        int ar[k];
        int dp[n+1];
        for (int i=0;i<=n;i++){
            dp[i]=-1;
        }
        dp[0]=0;
        for (int i=0;i<k;i++){
            cin>>ar[k-1-i];
        }
        for (int i=0;i<k;i++){
            for (int j=0;j<=n;j++){
                if (dp[j]!=-1&&j+ar[i]<=n&&dp[j]!=i+1&&dp[j+ar[i]]==-1){
                    dp[j+ar[i]]=i+1;
                }
            }
        }
        int x=n;
        while (dp[x]==-1)
            x--;
        n=x;
        while (x>0){
            printf ("%d ",ar[dp[x]-1]);
            x-=ar[dp[x]-1];
        }
        printf ("sum:%d\n",n);
    }
}
