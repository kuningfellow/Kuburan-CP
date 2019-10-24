#include <bits/stdc++.h>
using namespace std;
int con[105][105];
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc,kas=1;
	cin>>tc;
	while (tc--){
		int n,m;
		cin>>n>>m;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				con[i][j]=(1<<20);
				if (i==j)con[i][j]=0;
			}
		}
		for (int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			con[a][b]=1;
			con[b][a]=1;
		}
		int s,e;
		cin>>s>>e;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					con[j][k]=min(con[j][k],con[j][i]+con[i][k]);
				}
			}
		}
		int maxi=0;
		for (int i=0;i<n;i++){
			maxi=max(maxi,con[s][i]+con[i][e]);
		}
		printf ("Case %d: %d\n",kas++,maxi);
	}
}