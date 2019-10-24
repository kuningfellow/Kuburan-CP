#include <bits/stdc++.h>
using namespace std;
#define mod 1000003
long long int combi(long long int a, long long int b){
	long long int ret=1;
	long long int rat=1;
	for (long long int i=a-b+1;i<=a;i++){
		ret*=i%mod;
		ret%=mod;
	}
	for (long long int i=1;i<=b;i++){
		rat*=i%mod;
		rat%=mod;
	}
	int p=mod-2;
	long long int rut=1;
	while (p>0){
		if (p%2==1){
			rut*=rat;
			rut%=mod;
		}
		rat*=rat;
		rat%=mod;
		p/=2;
	}
	return (ret*rut)%mod;
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	cin>>tc;
	while (tc--){
		long long int n,l,r;
		cin>>n>>l>>r;
		r=r-l+1+n;
		long long int t,d;
		long long int res=1;
		while (r>0){
			res*=combi(r%mod,n%mod)%mod;
			res%=mod;
			r/=mod;
			n/=mod;
		}
		printf ("%lld\n",(res-1+mod)%mod);
	}
}