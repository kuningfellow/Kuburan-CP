#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int a,b,n;
		cin>>a>>b>>n;
		long long int res=1;
		while(b>0){
			if (b%2==1){
				res*=a;
				res%=n;
			}
			b/=2;
			a*=a;
			a%=n;
		}
		printf ("%lld\n",res);
	}
	cin>>tc;
}