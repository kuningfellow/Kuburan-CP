#include <bits/stdc++.h>
using namespace std;
int dp[805][4005];
int cost[4005][4005];
int fam[4005][4005];
int n,k;
void serc(int l, int r, int optl ,int optr, int k){
    if (l>r){
        return;
    }
    int mid=(l+r)/2;
    int res=(1<<30);
    int temp;
    int opt=-1;
    int br=min(optr,mid);
    for (int i=optl;i<=br;i++){
        temp=dp[k-1][i-1]+cost[i-1][mid-1];
        if (temp<res){
            res=temp;
            opt=i;
        }
    }
    dp[k][mid]=res;
    serc(l,mid-1,optl,opt,k);
    serc(mid+1,r,opt,optr,k);
}
char rem[10010];
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            cost[i][j]=(1<<28);
        }
    }
    getchar();
    for (int i=0;i<n;i++){
        fam[i][0]=0;
        gets(rem);
        int l=strlen(rem);
        int idx=1;
        for (int j=0;j<l;j++){
            if (rem[j]>='0'&&rem[j]<='9'){
                fam[i][idx++]=rem[j]-'0';
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=i+1;j++){
            fam[i][j]+=fam[i][j-1];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if (j==i){
                cost[i][j]=fam[j][j+1]-fam[j][i];
            }
            else{
                cost[i][j]=cost[i][j-1]+fam[j][j+1]-fam[j][i];
            }
        }
    }
    for (int i=0;i<=k;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=(1<<30);
        }
        dp[i][0]=0;
    }
    for (int i=1;i<=n;i++){
        dp[1][i]=cost[0][i-1];
    }
    for (int i=2;i<=k;i++){
        serc(1,n,1,n,i);
    }
    printf ("%d\n",dp[k][n]);
}