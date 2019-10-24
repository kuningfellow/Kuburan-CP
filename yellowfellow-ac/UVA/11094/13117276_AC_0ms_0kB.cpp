#include <bits/stdc++.h>
using namespace std;
char rem[25][25];
int m,n;
int vis[25][25];
char lan;
int fin(int x,int y){
	vis[x][y]=1;
	int ret=1;
	if (x+1<m&&vis[x+1][y]==0&&rem[x+1][y]==lan){
		ret+=fin(x+1,y);
	}
	if (vis[x][(y+1)%n]==0&&rem[x][(y+1)%n]==lan){
		ret+=fin(x,(y+1)%n);
	}
	if (x-1>=0&&vis[x-1][y]==0&&rem[x-1][y]==lan){
		ret+=fin(x-1,y);
	}
	if (vis[x][(y-1+n)%n]==0&&rem[x][(y-1+n)%n]==lan){
		ret+=fin(x,(y-1+n)%n);
	}
	return ret;
}
int main(){
	while (scanf("%d%d",&m,&n)!=EOF){
		if (m==0&&n==0)break;
		for (int i=0;i<m;i++){
			scanf("%s",rem[i]);
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				vis[i][j]=0;
			}
		}
		int x,y;
		cin>>x>>y;
		lan=rem[x][y];
		int shit=fin(x,y);
		shit=0;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (vis[i][j]==0&&rem[i][j]==lan){
					shit=max(shit,fin(i,j));
				}
			}
		}
		printf ("%d\n",shit);
	}
}