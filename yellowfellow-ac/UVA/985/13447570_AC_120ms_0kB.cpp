#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF){
		int ma[n][m][4];
		int vis[n][m][4];
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				for (int k=0;k<4;k++){
					ma[i][j][k]=0;
					vis[i][j][k]=0;
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (i==n-1&&j==m-1)continue;
				char rem[500];
				scanf("%s",rem);
				for (int k=0;k<strlen(rem);k++){
					if (rem[k]=='N'){
						ma[i][j][0]=1;
					}
					if (rem[k]=='E'){
						ma[i][j][1]=1;
					}
					if (rem[k]=='S'){
						ma[i][j][2]=1;
					}
					if (rem[k]=='W'){
						ma[i][j][3]=1;
					}
				}
			}
		}
		queue<pair<int,int> >q;
		q.push(pair<int,int>(0,0));
		vis[0][0][0]=1;
		int step=1;
		int ans=-1;
		while (!q.empty()){
			int siz=q.size();
			for (int i=0;i<siz;i++){
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				int phase=(step-1)%4;
				int up=ma[x][y][(4+0-phase)%4];
				int right=ma[x][y][(4+1-phase)%4];
				int down=ma[x][y][(4+2-phase)%4];
				int left=ma[x][y][(4+3-phase)%4];
				if (up==1&&x-1>=0&&vis[x-1][y][step%4]==0){
					vis[x-1][y][step%4]=1;
					if (x-1==n-1&&y==m-1){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x-1,y));
				}
				if (right==1&&y+1<m&&vis[x][y+1][step%4]==0){
					vis[x][y+1][step%4]=1;
					if (x==n-1&&y+1==m-1){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x,y+1));
				}
				if (down==1&&x+1<n&&vis[x+1][y][step%4]==0){
					vis[x+1][y][step%4]=1;
					if (x+1==n-1&&y==m-1){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x+1,y));
				}
				if (left==1&&y-1>=0&&vis[x][y-1][step%4]==0){
					vis[x][y-1][step%4]=1;
					if (x==n-1&&y-1==m-1){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x,y-1));
				}
			}
			if (ans!=-1)break;
			step++;
		}
		if (ans==-1)printf ("no path to exit\n");
		else printf ("%d\n",ans);
	}
}