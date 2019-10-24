#include<bits/stdc++.h>
using namespace std;
int ar[100005];
int main(){
	int tc;
	int kas = 1;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		int ans = 0;
		for (int i = n-1; i >= 0; i--){
			scanf("%d", &ar[i]);
		}
		for (int i = 1; i < n; i++){
			if (ar[i-1] - ar[i] >= ans){
				int add = 0;
				if (ans == ar[i-1] - ar[i]) add = 1;
				ans = max(ans, ar[i-1] - ar[i]);
				ans += add;
			}
		}
		if (ar[n-1] >= ans){
			if (ar[n-1] == ans) ans++;
			else ans = ar[n-1];
		}
		printf ("Case %d: %d\n", kas++, ans);
	}
}