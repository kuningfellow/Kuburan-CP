#include<bits/stdc++.h>
using namespace std;
struct dat{
	int monet;
	int time;
	bool operator<(const dat &a){
		if (time!=a.time){
			return time<a.time;
		}
		else return monet>a.monet;
	}
};
dat ar[10005];
int dp[10005][50];
int n;
int serc(int x, int t){
	if (x==n){
		return 0;
	}
	if (dp[x][t]!=-1){
		return dp[x][t];
	}
	int ret=0;
	if (t<=ar[x].time){
		ret=max(ret,ar[x].monet+serc(x+1,t+1));
	}
	ret=max(ret,serc(x+1,t));
	return dp[x][t]=ret;
}
int main(){
	int T;
	cin>>n>>T;
	for (int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ar[i].monet=a;
		ar[i].time=b;
	}
	sort(ar,ar+n);
	for (int i=0;i<n;i++){
		for (int j=0;j<T;j++){
			dp[i][j]=-1;
		}
	}
	printf ("%d\n",serc(0,0));
}