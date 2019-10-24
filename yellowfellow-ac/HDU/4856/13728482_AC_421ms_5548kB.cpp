#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >cost[35];
int dp[16][(1<<16)];
int m;
int serc(int x, int mask){
	if (mask==(1<<m)-1){
		return 0;
	}
	int ret=(1<<29);
	if (dp[x][mask]!=-1){
		return dp[x][mask];
	}
	for (int i=0;i<cost[x].size();i++){
		if ((mask&(1<<cost[x][i].first))==0){
			ret=min(ret,cost[x][i].second+serc(cost[x][i].first,mask|(1<<cost[x][i].first)));
			
		}
	}
	return dp[x][mask]=ret;
}
int main(){
	int n;
	while (scanf("%d%d",&n,&m)!=EOF){
		for (int i=0;i<35;i++){
			cost[i].clear();
		}
		char rem[n][n+1];
		for (int i=0;i<n;i++){
			scanf("%s",rem[i]);
		}
		int ar[m*2][2];
		for (int i=0;i<m;i++){
			scanf("%d%d%d%d",&ar[i][0],&ar[i][1],&ar[i+m][0],&ar[i+m][1]);
			ar[i][0]--;
			ar[i][1]--;
			ar[i+m][0]--;
			ar[i+m][1]--;
		}
		for (int i=m;i<m*2;i++){
			queue<pair<int,int> >q;
			int step=0;
			q.push(pair<int,int>(ar[i][0],ar[i][1]));
			int vis[n][n];
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					vis[j][k]=0;
				}
			}
			int vis2[m];
			for (int j=0;j<m;j++){
				vis2[j]=0;
			}
			vis[ar[i][0]][ar[i][1]]=1;
			while (!q.empty()){
				int siz=q.size();
				for (int j=0;j<siz;j++){
					int x=q.front().first;
					int y=q.front().second;
					q.pop();
					for (int j=0;j<m;j++){
						if (j==i)continue;
						if (x==ar[j][0]&&y==ar[j][1]&&vis2[j]==0){
							cost[i-m].push_back(pair<int,int>(j,step));
							vis2[j]=1;
						}
					}
					if (x-1>=0&&rem[x-1][y]!='#'&&vis[x-1][y]==0){
						q.push(pair<int,int>(x-1,y));
						vis[x-1][y]=1;
					}
					if (x+1<n&&rem[x+1][y]!='#'&&vis[x+1][y]==0){
						q.push(pair<int,int>(x+1,y));
						vis[x+1][y]=1;
					}
					if (y-1>=0&&rem[x][y-1]!='#'&&vis[x][y-1]==0){
						q.push(pair<int,int>(x,y-1));
						vis[x][y-1]=1;
					}
					if (y+1<n&&rem[x][y+1]!='#'&&vis[x][y+1]==0){
						q.push(pair<int,int>(x,y+1));
						vis[x][y+1]=1;
					}
				}
				step++;
			}
		}
		int ans=(1<<29);
		for (int i=0;i<m;i++){
			for (int j=0;j<(1<<16);j++){
				dp[i][j]=-1;
			}
		}
		for (int j=0;j<m;j++){
			int lol=serc(j,(1<<j));
			ans=min(ans,lol);
		}
		if (ans==(1<<29)){
			printf ("-1\n");
		}
		else printf ("%d\n",ans);
	}
}