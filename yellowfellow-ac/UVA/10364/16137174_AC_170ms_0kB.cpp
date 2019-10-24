//10364 Square
//pruning
#include<bits/stdc++.h>
using namespace std;
int val;
int mark[20];
int ar[20];
int n;
void serc(int x, int r, int t, int l){
	if (x > t) {
		return;
	}
	if (x == t) {
		x = 0;
		l = 0;
		r--;
	}
	if (r == 0) {
		val = 1;
		return;
	}
	for (int i = l; i < n && !val; i++) {
		if (mark[i] == 0) {
			mark[i] = 1;
			serc(x + ar[i], r, t, i + 1);
			mark[i] = 0;
		}
	}
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
			sum += ar[i];
		}
		sort(ar, ar + n);
		for (int i = 0; i < n; i++) {
			mark[i] = 0;
		}
		if (sum % 4 != 0){
			printf("no\n");
			continue;
		}
		sum /= 4;
		val = 0;
		serc(0, 4, sum, 0);
		if (val == 1) printf("yes\n");
		else printf("no\n");
	}
}