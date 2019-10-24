#include <bits/stdc++.h>
using namespace std;
int n,m,c;
int vis[505][505];
char rem[505][505];
void kil(int x, int y){
	vis[x][y]=1;
	if (x+1<n&&vis[x+1][y]==0&&rem[x+1][y]=='.'){
		kil(x+1,y);
	}
	if (x-1>=0&&vis[x-1][y]==0&&rem[x-1][y]=='.'){
		kil(x-1,y);
	}
	if (y+1<m&&vis[x][y+1]==0&&rem[x][y+1]=='.'){
		kil(x,y+1);
	}
	if (y-1>=0&&vis[x][y-1]==0&&rem[x][y-1]=='.'){
		kil(x,y-1);
	}
	if (c>0){
		c--;
		vis[x][y]=-1;
	}
}
int main(){
	cin>>n>>m>>c;
	queue<pair<int,int> >q;
	for (int i=0;i<n;i++){
		scanf("%s",rem[i]);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (vis[i][j]==0&&rem[i][j]=='.'){
				kil(i,j);
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (vis[i][j]==-1){
				printf ("X");
			}
			else{
				printf ("%c",rem[i][j]);
			}
		}
		printf ("\n");
	}
}