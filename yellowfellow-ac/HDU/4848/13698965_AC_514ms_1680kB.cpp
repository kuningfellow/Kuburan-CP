#include <bits/stdc++.h>
using namespace std;
int cost[35][35];
int dead[35];
int vis[35];
int ans;
int n;
void serc(int x, int time, int total, int take){
    if (ans!=-1&&total>=ans)return;
    if (take==n){
        if (ans==-1){
            ans=total;
        }
        else{
//        	printf ("%d and %d\n",ans,total);
            ans=min(ans,total);
        }
        return;
    }
    for (int i=1;i<n;i++){
    	if (vis[i]==0&&dead[i]<time+cost[x][i])return;
    }
    for (int i=1;i<n;i++){
        if (vis[i]==1)continue;
//        if (dead[i]<time+cost[x][i])continue;
        vis[i]=1;
        serc(i,time+cost[x][i],total+(n-take)*cost[x][i],take+1);
        vis[i]=0;
    }
}
int main(){
    while (scanf("%d",&n)!=EOF){
        for (int i=0;i<n;i++){
            vis[i]=0;
            for (int j=0;j<n;j++){
                scanf("%d",&cost[i][j]);
            }
        }
        for (int i=1;i<n;i++){
            scanf("%d",&dead[i]);
        }
        dead[0]=(1<<29);
//        n=30;
//        for (int i=0;i<n;i++){
//            for (int j=0;j<n;j++){
//                if (i==j)cost[i][j]=0;
//                else cost[i][j]=1;
//            }
//        }
//        for (int i=0;i<n;i++){
//            dead[i]=(1<<29);
//        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    cost[j][k]=min(cost[j][i]+cost[i][k],cost[j][k]);
                }
            }
        }
        ans=-1;
        vis[0]=1;
//        n=20;
        serc(0,0,0,1);
        printf ("%d\n",ans);
    }
}