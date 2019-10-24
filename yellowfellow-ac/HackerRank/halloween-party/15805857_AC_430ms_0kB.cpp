#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int k;
		cin >> k;
		long long int ans = 0;
		for (int i = 1; i < k; i++){
			ans = max(ans, (long long)i * ((long long)k-i));
		}
		printf ("%lld\n", ans);
	}
}