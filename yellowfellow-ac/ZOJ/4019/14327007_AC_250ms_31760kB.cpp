#include <bits/stdc++.h>
using namespace std;
long long int ar[2005];
long long int br[2005];
long long int wa[2005];
long long int wb[2005];
long long int dp[2005][2005];
long long int k1,k2,c;
int n,m;
long long int serc(int x, int y){
	if (dp[x][y]!=-1){
		return dp[x][y];
	}
	long long int temp=0;
	if (x+1<=n&&wa[x+1]+wb[y]<=c){
		temp=max(temp,k1*(c-wa[x+1]-wb[y])+serc(x+1,y));
	}
	if (y+1<=m&&wa[x]+wb[y+1]<=c){
		temp=max(temp,k2*(c-wa[x]-wb[y+1])+serc(x,y+1));
	}
	return dp[x][y]=temp;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		scanf("%lld%lld%lld",&k1,&k2,&c);
		scanf("%d%d",&n,&m);
		ar[0]=0;
		br[0]=0;
		for (int i=1;i<=n;i++){
			scanf("%lld",&ar[i]);
		}
		for (int i=1;i<=m;i++){
			scanf("%lld",&br[i]);
		}
		for (int i=0;i<=n;i++){
			for (int j=0;j<=m;j++){
				dp[i][j]=-1;
			}
		}
		sort(ar,ar+n+1);
		sort(br,br+m+1);
		wa[0]=ar[0];
		wb[0]=br[0];
		for (int i=1;i<=n;i++){
			wa[i]=wa[i-1]+ar[i];
		}
		for (int i=1;i<=m;i++){
			wb[i]=wb[i-1]+br[i];
		}
		printf ("%lld\n",serc(0,0));
	}
}