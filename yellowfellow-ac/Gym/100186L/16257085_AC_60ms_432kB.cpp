#include<bits/stdc++.h>
using namespace std;
vector<int> lis;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		lis.push_back(a);
	}
	sort(lis.begin(), lis.end());
	if (n < k+1) printf("-1\n");
	else printf("%d\n", lis[k]);
}