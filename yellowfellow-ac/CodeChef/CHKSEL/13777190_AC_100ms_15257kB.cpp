#include <bits/stdc++.h>
using namespace std;
int p;
long long int combi(long long int a, long long int b){
	long long int ret=1;
	for (long long int i=a;i>a-b;i--){
		ret*=i;
		ret%=p;
	}
	long long int rat=1;
	for (long long int i=1;i<=b;i++){
		rat*=i;
		rat%=p;
	}
	int n=p-2;
	long long int mul=rat;
	rat=1;
	while (n>0){
		if (n%2==1){
			rat*=mul;
			rat%=p;
		}
		mul*=mul;
		mul%=p;
		n/=2;
	}
	return (ret*rat)%p;
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int n,k;
		cin>>n>>k>>p;
		long long int ar[66][2];
		int siz=0;
		long long int res=1;
		while (n>0){
			res*=combi(n%p,k%p)%p;
			res%=p;
			n/=p;
			k/=p;
		}
		printf ("%lld\n",res);
	}
}