#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n,m;
		scanf("%d%d",&n,&m);
		int ar[n][m];
		int vis[n][m][2];
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				vis[i][j][0]=vis[i][j][1]=-1;
				scanf("%d",&ar[i][j]);
			}
		}
		int x0,y0,x1,y1;
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		x0--;
		y0--;
		x1--;
		y1--;
		int step=0;
		int val=1;
		queue<pair<int,int> >q;
		q.push(pair<int,int>(x0,y0));
		vis[x0][y0][0]=0;
		while (!q.empty()&&(vis[x1][y1][0]==-1||vis[x1][y1][1]==-1)){
			int siz=q.size();
			for (int i=0;i<siz;i++){
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				int me=step%2;
				if ((ar[x][y]^me)==1){
					if (y+1<m&&vis[x][y+1][me^1]==-1){
						q.push(pair<int,int>(x,y+1));
						vis[x][y+1][me^1]=step+1;
					}
					if (y-1>=0&&vis[x][y-1][me^1]==-1){
						q.push(pair<int,int>(x,y-1));
						vis[x][y-1][me^1]=step+1;
					}
				}
				else{
					if (x+1<n&&vis[x+1][y][me^1]==-1){
						q.push(pair<int,int>(x+1,y));
						vis[x+1][y][me^1]=step+1;
					}
					if (x-1>=0&&vis[x-1][y][me^1]==-1){
						q.push(pair<int,int>(x-1,y));
						vis[x-1][y][me^1]=step+1;
					}
				}
			}
			step++;
		}
		if (vis[x1][y1][0]==-1&&vis[x1][y1][1]==-1){
			printf ("-1\n");
		}
		else{
			if (vis[x1][y1][0]!=-1){
				printf ("%d\n",vis[x1][y1][0]);
			}
			else{
				printf ("%d\n",vis[x1][y1][1]);
			}
		}
	}
}