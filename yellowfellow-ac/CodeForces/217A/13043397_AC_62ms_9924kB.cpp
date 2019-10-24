#include <bits/stdc++.h>
using namespace std;
int mark[1005][1005];
int vis[1005][1005];
void dfs(int x, int y){
	vis[x][y]=1;
	for (int i=0;i<1005;i++){
		if (mark[x][i]==1&&vis[x][i]==0){
			dfs(x,i);
		}
		if (mark[i][y]==1&&vis[i][y]==0){
			dfs(i,y);
		}
	}
}
int main(){
	int n,x,y,coun=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x>>y;
		mark[x][y]=1;
	}
	for (int i=0;i<1005;i++){
		for (int j=0;j<1005;j++){
			if (mark[i][j]==1&&vis[i][j]==0){
				dfs(i,j);
				coun++;
			}
		}
	}
	printf ("%d\n",coun-1);
}