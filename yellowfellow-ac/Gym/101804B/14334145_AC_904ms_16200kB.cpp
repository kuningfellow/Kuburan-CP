#include <bits/stdc++.h>
using namespace std;
char hash[1005][15];
int ar[1005];
int vis[2005];
vector<int>lis[2005];
int kit,m;
int target;
int dp[1005][2005][2];
int serc(int x, int w){
	if ((kit+w)*2>=target){
		return 0;
	}
	if (x==m){
		return 100000;
	}
	if (dp[x][w][0]!=-1){
		return dp[x][w][0];
	}
	int rem=serc(x+1,w);
	int ram=ar[x]+serc(x+1,w+ar[x]);
	if (rem<=ram){
		dp[x][w][0]=rem;
		dp[x][w][1]=w;
	}
	else{
		dp[x][w][0]=ram;
		dp[x][w][1]=w+ar[x];
	}
	return dp[x][w][0];
}
int main(){
	scanf("%d%d",&kit,&m);
	for (int i=0;i<m;i++){
		scanf("%s",hash[i]);
		scanf("%d",&ar[i]);
	}
	int n;
	scanf("%d",&n);
	for (int k=0;k<n;k++){
		scanf("%d",&target);
		if (vis[target]==0){
			for (int i=0;i<m;i++){
				for (int j=0;j<target;j++){
					dp[i][j][0]=dp[i][j][1]=-1;
				}
			}
			serc(0,0);
			vis[target]=1;
			int x=0,w=0;
			while ((w+kit)*2<target&&x<m){
				if (dp[x][w][1]!=w){
					lis[target].push_back(x);
				}
				w=dp[x][w][1];
				x++;
			}
			if ((w+kit)*2<target){
				printf ("-1\n");
				vis[target]=2;
				continue;
			}
		}
		if (vis[target]==2){
			printf ("-1\n");
			continue;
		}
		printf ("%d ",lis[target].size());
		for (int i=0;i<lis[target].size();i++){
			if (i!=0)printf (" ");
			printf ("%s",hash[lis[target][i]]);
		}
		printf ("\n");
	}
}