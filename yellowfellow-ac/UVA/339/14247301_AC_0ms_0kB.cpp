//UVA 339 SameGame Simulation
#include <bits/stdc++.h>
using namespace std;
int main(){
	int kas=1;
	while (1<2){
		int m,n;
		scanf("%d%d",&m,&n);
		if (m==0&&n==0)break;
		int ar[m][n];
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				scanf("%d",&ar[i][j]);
			}
		}
		int x,y;
		while (1<2){
			scanf("%d%d",&x,&y);
			if (x==0&&y==0)break;
			x--;
			y--;
			if (x>=m||x<0||y>=n||y<0||ar[x][y]==-1)continue;
			queue<pair<int,int> >q;
			stack<pair<int,int> >st;
			int vis[m][n];
			for (int i=0;i<m;i++){
				for (int j=0;j<n;j++){
					vis[i][j]=0;
				}
			}
			int col=0;
			q.push(pair<int,int>(x,y));
			while (!q.empty()){
				int ex=q.front().first;
				int ey=q.front().second;
				q.pop();
				if (vis[ex][ey]==1)continue;
				vis[ex][ey]=1;
				col++;
				st.push(pair<int,int>(ex,ey));
				if (ex-1>=0&&ar[ex-1][ey]==ar[x][y]&&vis[ex-1][ey]==0){
					q.push(pair<int,int>(ex-1,ey));
				}
				if (ex+1<m&&ar[ex+1][ey]==ar[x][y]&&vis[ex+1][ey]==0){
					q.push(pair<int,int>(ex+1,ey));
				}
				if (ey-1>=0&&ar[ex][ey-1]==ar[x][y]&&vis[ex][ey-1]==0){
					q.push(pair<int,int>(ex,ey-1));
				}
				if (ey+1<n&&ar[ex][ey+1]==ar[x][y]&&vis[ex][ey+1]==0){
					q.push(pair<int,int>(ex,ey+1));
				}
			}
			if (col>1){
				while (!st.empty()){
					int ex=st.top().first;
					int ey=st.top().second;
					ar[ex][ey]=-1;
					st.pop();
				}
			}
			while (!st.empty())st.pop();
			while (1<2){
				int rep=0;
				for (int i=0;i<n;i++){
					for (int j=0;j<m-1;j++){
						if (ar[j][i]==-1&&ar[j+1][i]!=-1){
							rep=1;
							ar[j][i]=ar[j+1][i];
							ar[j+1][i]=-1;
						}
					}
				}
				if (rep==0)break;
			}
			while (1<2){
				int rep=0;
				for (int i=0;i<n-1;i++){
					int shift=1;
					for (int j=0;j<m;j++){
						if (ar[j][i]!=-1){
							shift=0;
							break;
						}
					}
					if (shift==1){
						int val=0;
						for (int j=0;j<m;j++){
							if (ar[j][i+1]!=-1){
								val=1;
								break;
							}
						}
						if (val==0)continue;
						rep=1;
						for (int j=0;j<m;j++){
							ar[j][i]=ar[j][i+1];
							ar[j][i+1]=-1;
						}
					}
				}
				if (rep==0)break;
			}
		}
		int win=1;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (ar[i][j]!=-1){
					win=0;
					break;
				}
			}
		}
		if (kas!=1)printf ("\n");
		printf ("Grid %d.\n",kas++);
		if (win==1){
			printf ("    Game Won\n");
		}
		else{
			for (int i=m-1;i>=0;i--){
				for (int j=0;j<n;j++){
					if (j==0)printf ("    ");
					if (j!=0)printf (" ");
					if (ar[i][j]==-1)printf (" ");
					else printf ("%d",ar[i][j]);
				}
				printf ("\n");
			}
		}
	}
}