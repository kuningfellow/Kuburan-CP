#include <bits/stdc++.h>
using namespace std;
int ma[205][205];
int col[205][205];
int n,m;
void black(int x, int y, int c){
	col[x][y]=c;
	if (x+1<n && ma[x+1][y]==1 && col[x+1][y]==0)
		black(x+1,y,c);
	if (x-1>=0 && ma[x-1][y]==1 && col[x-1][y]==0)
		black(x-1,y,c);
	if (y+1<m*4 && ma[x][y+1]==1 && col[x][y+1]==0)
		black(x,y+1,c);
	if (y-1>=0 && ma[x][y-1]==1 && col[x][y-1]==0)
		black(x,y-1,c);
}
int match;
int val=0;
void white(int x, int y){
	if (ma[x][y]==1){
		if (match==0){
			match=col[x][y];
			return;
		}
		else if (match!=col[x][y]){
			val=0;
			return;
		}
		else {
			return;
		}
	}
	if (x+1>=n||x-1<0||y+1>=m*4||y-1<0){
		val=0;
		return;
	}
	col[x][y]=-1;
	if (x+1<n && col[x+1][y]!=-1 ){
		white(x+1,y);
	}
	if (x-1>=0 && col[x-1][y]!=-1){
		white(x-1,y);
	}
	if (y+1<m*4 && col[x][y+1]!=-1 ){
		white(x,y+1);
	}
	if (y-1>=0 && col[x][y-1]!=-1 ){
		white(x,y-1);
	}
	return;
}
int main(){
	int kas=1;
	while (1<2){
		cin>>n>>m;
		if (n==0&&m==0)break;
		char rem[n][m+1];
		for (int i=0;i<n;i++){
			scanf("%s",rem[i]);
			for (int j=0;j<m;j++){
				int v=0;
				if (rem[i][j]>='a'&&rem[i][j]<='z'){
					v=rem[i][j]-'a'+10;
				}
				else{
					v=rem[i][j]-'0';
				}
				for (int k=3;k>=0;k--){
					ma[i][j*4+(3-k)]=((v&(1<<k))>0);
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<m*4;j++){
				col[i][j]=0;
			}
		}
		int lv=1;
		vector<int>coun;
		coun.push_back(0);
		for (int i=0;i<n;i++){
			for (int j=0;j<m*4;j++){
				if (ma[i][j]==1&&col[i][j]==0){
					black(i,j,lv++);
					coun.push_back(0);
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<m*4;j++){
				if (ma[i][j]==0 && col[i][j]==0){
					val=1;
					match=0;
					white(i,j);
					if (val==1){
						coun[match]++;
					}
				}
			}
		}
		int ans[6]={0,0,0,0,0,0};
		for (int i=1;i<coun.size();i++){
			ans[coun[i]]++;
		}
		printf ("Case %d: ",kas++);
		for (int i=0;i<ans[1];i++)printf ("A");
		for (int i=0;i<ans[5];i++)printf ("D");
		for (int i=0;i<ans[3];i++)printf ("J");
		for (int i=0;i<ans[2];i++)printf ("K");
		for (int i=0;i<ans[4];i++)printf ("S");
		for (int i=0;i<ans[0];i++)printf ("W");
		printf ("\n");
	}
}