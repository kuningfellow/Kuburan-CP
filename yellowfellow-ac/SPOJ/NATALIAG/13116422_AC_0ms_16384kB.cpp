#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int m,n;
		cin>>m>>n;
		char rem[m][n+1];
		int vis[m][n];
		int x,y;
		int tx,ty;
		for (int i=0;i<m;i++){
			scanf("%s",rem[i]);
			for (int j=0;j<n;j++){
				vis[i][j]=0;
				if (rem[i][j]=='$'){
					x=i;
					y=j;
				}
				if (rem[i][j]=='#'){
					tx=i;
					ty=j;
				}
			}
		}
		queue<pair<int,int> >q;
		q.push(pair<int,int>(x,y));
		int step=0;
		while (!q.empty()&&vis[tx][ty]==0){
			int siz=q.size();
			for (int i=0;i<siz;i++){
				x=q.front().first;
				y=q.front().second;
				if (x+1<m&&vis[x+1][y]==0&&rem[x+1][y]!='*'){
					vis[x+1][y]=1;
					q.push(pair<int,int>(x+1,y));
				}
				if (y+1<n&&vis[x][y+1]==0&&rem[x][y+1]!='*'){
					vis[x][y+1]=1;
					q.push(pair<int,int>(x,y+1));
				}
				if (x-1>=0&&vis[x-1][y]==0&&rem[x-1][y]!='*'){
					vis[x-1][y]=1;
					q.push(pair<int,int>(x-1,y));
				}
				if (y-1>=0&&vis[x][y-1]==0&&rem[x][y-1]!='*'){
					vis[x][y-1]=1;
					q.push(pair<int,int>(x,y-1));
				}
				q.pop();
			}
			step++;
		}
		if (vis[tx][ty]==0){
			printf ("-1\n");
		}
		else printf ("%d\n",step);
	}
}