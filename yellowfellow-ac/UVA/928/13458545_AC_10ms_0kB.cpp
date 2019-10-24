#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	cin>>tc;
	while (tc--){
		int n,m;
		cin>>n>>m;
		char rem[n][m+1];
		int vis[n][m][3];
		int sx,sy;
		for (int i=0;i<n;i++){
			scanf("%s",rem[i]);
			for (int j=0;j<m;j++){
				if (rem[i][j]=='S'){
					sx=i;
					sy=j;
				}
				vis[i][j][0]=vis[i][j][1]=vis[i][j][2]=0;
			}
		}
		queue<pair<int,int> >q;
		q.push(pair<int,int>(sx,sy));
		vis[sx][sy][0]=1;
		int step=1;
		int ans=-1;
		while (!q.empty()){
			int siz=q.size();
			for (int i=0;i<siz;i++){
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				int move=(step-1)%3+1;
				int val=1;
				for (int j=1;j<=move;j++){
					if (!(x+j<n&&rem[x+j][y]!='#')){
						val=0;
						break;
					}
				}
				if (val==1&&vis[x+move][y][step%3]==0){
					vis[x+move][y][step%3]=1;
					if (rem[x+move][y]=='E'){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x+move,y));
				}
				val=1;
				for (int j=1;j<=move;j++){
					if (!(x-j>=0&&rem[x-j][y]!='#')){
						val=0;
						break;
					}
				}
				if (val==1&&vis[x-move][y][step%3]==0){
					vis[x-move][y][step%3]=1;
					if (rem[x-move][y]=='E'){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x-move,y));
				}
				val=1;
				for (int j=1;j<=move;j++){
					if (!(y-j>=0&&rem[x][y-j]!='#')){
						val=0;
						break;
					}
				}
				if (val==1&&vis[x][y-move][step%3]==0){
					vis[x][y-move][step%3]=1;
					if (rem[x][y-move]=='E'){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x,y-move));
				}
				val=1;
				for (int j=1;j<=move;j++){
					if (!(y+j<m&&rem[x][y+j]!='#')){
						val=0;
						break;
					}
				}
				if (val==1&&vis[x][y+move][step%3]==0){
					vis[x][y+move][step%3]=1;
					if (rem[x][y+move]=='E'){
						ans=step;
						break;
					}
					q.push(pair<int,int>(x,y+move));
				}
				if (ans!=-1)
					break;
			}
			if (ans!=-1)
				break;
			step++;
		}
		if (ans==-1){
			printf ("NO\n");
		}
		else printf ("%d\n",ans);
	}
}