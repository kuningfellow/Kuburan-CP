#include <bits/stdc++.h>
using namespace std;
long long int cost[100005];
long long int ar[100005];
long long int dp[12][100005];
void serc(int l, int r, int lcut, int rcut, int k){
	if (l>r)return;
	int mid=(l+r)/2;
	long long int res=(1ll<<60);
	long long int temp;
	int opt=-1;
	int cap=min(mid,rcut);
	for (int i=lcut;i<=cap;i++){
		temp=dp[k-1][i-1]+cost[mid]-ar[i-1]*(mid-i+1)-cost[i-1];
		if (temp<res){
			res=temp;
			opt=i;
		}
	}
	dp[k][mid]=res;
	serc(l,mid-1,lcut,opt,k);
	serc(mid+1,r,opt,rcut,k);
}
int main(){
	int n,k;
	cin>>n>>k;
	ar[0]=0;
	cost[0]=0;
	for (int i=0;i<n;i++){
		cin>>ar[n-i];
	}
	long long int car=0;
	for (int i=1;i<=n;i++){
		ar[i]+=ar[i-1];
	}
	for (int i=1;i<=n;i++){
		cost[i]=cost[i-1]+ar[i-1];
	}
	dp[1][0]=0;
	for (int i=1;i<=n;i++){
		dp[1][i]=cost[i];
	}
	for (int i=2;i<=k;i++){
		serc(1,n,1,n,i);
	}
	printf ("%lld\n",dp[k][n]);
}