#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int n;
		cin>>n;
		long long int sum=3*n*(n-1)/2;
		sum+=n*2;
		printf ("%lld\n",sum%1000007);
	}
}