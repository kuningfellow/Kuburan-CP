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
		int n,e,k;
		cin>>n>>e>>k;
		e--;
		int con[n][n];
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				con[i][j]=(1<<28);
				if (i==j)con[i][j]=0;
			}
		}
		int m;
		cin>>m;
		for (int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			con[a-1][b-1]=c;
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					con[j][k]=min(con[j][k],con[j][i]+con[i][k]);
				}
			}
		}
		int coun=0;
		for (int i=0;i<n;i++){
			if (con[i][e]<=k){
				coun++;
			}
		}
		printf ("%d\n",coun);
		if (tc!=0)printf ("\n");
	}
}