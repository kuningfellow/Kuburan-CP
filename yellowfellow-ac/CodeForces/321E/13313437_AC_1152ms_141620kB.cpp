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
    for (int i=optl;i<=optr;i++){
        temp=dp[k-1][i-1]+cost[i][mid];
        if (temp<res){
            res=temp;
            opt=i;
        }
    }
    dp[k][mid]=res;
    serc(l,mid-1,optl,opt,k);
    serc(mid+1,r,opt,optr,k);
}
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            cost[i][j]=(1<<28);
        }
    }
    getchar();
    char rem[10005];
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
        // printf ("%s\n",rem);
        // for (int j=0;j<n;j++){
        //     gets(rem);
        //     fam[i][j+1]=rem[0]-'0';
        //     // scanf("%d",&fam[i][j+1]);
        // }
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
    // for (int i=0;i<n;i++){
    //     for (int j=i;j<n;j++){
    //         printf ("cost from %d to %d is %d\n",i,j,cost[i][j]);
    //     }
    // }
    for (int i=0;i<=k;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=(1<<30);
        }
    }
    for (int i=0;i<n;i++){
        dp[1][i]=cost[0][i];
    }
    for (int i=2;i<=k;i++){
        serc(0,n,0,n,i);
    }
    // for (int i=0;i<n;i++){
    //     printf ("%d ",dp[3][i]);
    // }
    printf ("%d\n",dp[k][n-1]);
}