#include <bits/stdc++.h>
using namespace std;
int n;
int vis[205];
int con[205][205];
int dfs(int x,int p,int m){
	vis[x]=m;
	int ret=1;
	int tmp;
	for (int i=0;i<n;i++){
		if (con[x][i]==1&&vis[i]==-1){
			ret+=dfs(i,p,m^1);
		}
		if (con[x][i]==1&&vis[i]==m&&x!=p){
			ret--;
		}
	}
//	printf ("%d return %d\n",x,ret);
	return ret;
}
int main(){
	int m;
	cin>>n>>m;
	int x,y;
	for (int i=0;i<205;i++){
		for (int j=0;j<205;j++){
			con[i][j]=0;
		}
	}
	for (int i=0;i<m;i++){
		cin>>x>>y;
		x--;
		y--;
		con[x][y]=1;
		con[y][x]=1;
	}
	for (int i=0;i<n;i++){
		vis[i]=-1;
	}
	int ans=0;
	int temp=0;
	for (int i=0;i<n;i++){
		if (vis[i]==-1){
			temp=dfs(i,i,0);
//			printf ("%d %d\n",temp,i);
			ans+=temp;
		}
	}
	printf ("%d\n",n-ans/2*2);
}