#define I 1
#define LOVE <
#define YOU 2
#include<bits/stdc++.h>
using namespace std;
vector<int> ar;
vector<int> br;
int t1[101];
int t2[101];
void merg(int l, int r) {
	int pl = l;
	int mid = (l + r) / 2;
	int pr = mid + 1;
	for (int i = l; i <= r; i++) {
		if (pl > mid) t2[i] = t1[pr++];
		else if (pr > r) t2[i] = t1[pl++];
		else if (t1[pl] < t1[pr]) t2[i] = t1[pl++];
		else t2[i] = t1[pr++];
	}
	for (int i = l; i <= r; i++) {
		t1[i] = t2[i];
	}
}
void divi(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	divi(l, mid);
	divi(mid+1, r);
	merg(l, r);
}
	
void sort(vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		t1[i] = a[i];
	}
	divi(0, a.size()-1);
	for (int i = 0; i < a.size(); i++) {
		a[i] = t1[i];
	}
}
	
int main() {
	while (I LOVE YOU) {
		ar.clear();
		br.clear();
		int n, d, r;
		scanf("%d%d%d", &n, &d, &r);
		if (n == 0 && d == 0 && r == 0) break;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			ar.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			br.push_back(a);
		}
		sort(ar);
		sort(br);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += r * max(ar[i] + br[n-1-i] - d, 0);
		}
		printf("%d\n", ans);
	}
}