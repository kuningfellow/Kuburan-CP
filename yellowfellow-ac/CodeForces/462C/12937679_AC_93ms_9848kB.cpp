#include <bits/stdc++.h>
using namespace std;
long long int ar[500006];
long long int dp[500006];
int main(){
	int n;
	cin>>n;
	long long int sum=0;
	for (int i=0;i<n;i++){
		scanf("%lld",&ar[i]);
	}
	sort(ar,ar+n);
	dp[0]=0;
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1]+ar[i-1];
	}
	for (int i=1;i<n;i++){
		sum+=dp[n]-dp[i-1]+ar[i-1];
	}
	printf ("%lld\n",sum+ar[n-1]);
}