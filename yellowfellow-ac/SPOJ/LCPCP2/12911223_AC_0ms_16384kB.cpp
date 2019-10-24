#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	int kas=1;
	while (tc--){
		long long int ret=1,a,b,k;
		cin>>a>>b>>k;
		while (b>0){
			if (b%2==1){
				ret*=a;
				ret%=k;
			}
			a*=a;
			a%=k;
			b/=2;
		}
		printf ("%d. %lld\n",kas++,ret);
	}
}