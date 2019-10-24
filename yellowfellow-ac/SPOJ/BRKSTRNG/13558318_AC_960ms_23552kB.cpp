#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int mid[1005][1005];
int pos[1005];
int n;
void serc(){
    for (int i=0;i<n;i++){
        for (int j=0;j+i<n;j++){
            int k=i+j;
            if (i<2){
                mid[j][k]=j;
                dp[j][k]=0;
                continue;
            }
            int l=mid[j][k-1];
            int r=mid[j+1][k];
            dp[j][k]=(1<<28);
            int temp;
            for (int m=l;m<=r;m++){
                temp=dp[j][m]+dp[m][k]+pos[k]-pos[j];
                if (dp[j][k]>temp){
                    dp[j][k]=temp;
                    mid[j][k]=m;
                }
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m;
    while (scanf("%d%d",&m,&n)!=EOF){
        n++;
        pos[0]=0;
        for (int i=1;i<n;i++){
            scanf("%d",&pos[i]);
        }
        pos[n]=m;
        n++;
        serc();
        printf ("%d\n",dp[0][n-1]);
    }
}