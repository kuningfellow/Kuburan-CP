#include<bits/stdc++.h>
using namespace std;
int ar[105];
int br[105];
int id[105];
int mark[105];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int L = n;
	int R = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		br[a-1] = b;
		id[a-1] = i+1;
		L = min(L, a-1);
		R = max(R, a-1);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		vector<int> ans;
		stack<int> last;
		for (int j = 0; j < n; j++) {
			mark[j] = 0;
		}
		for (int j = i; j < n; j++) {
			if (br[j] > 0 && mark[j] == 0) {
				int tmp = br[j];
				int val = 1;
				for (int k = j; k >= i && val; k--) {
					if (mark[k] != 1)tmp += ar[k];
					if (tmp < 0) val = 0;
				}
				if (val) {
					for (int k = i; k <= j; k++) mark[k] = 1;
					ans.push_back(id[j]);
				}
				else {
					last.push(id[j]);
				}
			}
		}
		for (int j = i; j >= 0; j--) {
			if (br[j] > 0 && mark[j] == 0) {
				int tmp = br[j];
				int val = 1;
				for (int k = j; k <= i && val; k++) {
					if (mark[k] != 1) tmp += ar[k];
					if (tmp < 0) val = 0;
				}
				if (val) {
					for (int k = j; k <= i; k++) mark[k] = 1;
					ans.push_back(id[j]);
				}
				else {
					last.push(id[j]);
				}
			}
		}
		int val = 1;
		for (int j = L; j <= R; j++) {
			if (mark[j] != 1) {
				val = 0;
				break;
			}
		}
		if (val) {
			printf("%d\n", i+1);
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			while (!last.empty()) {
				printf("%d ", last.top());
				last.pop();
			}
			printf("\n");
			return 0;
		}
		
		
		ans.clear();
		while (!last.empty()) {
			last.pop();
		}
		for (int j = 0; j < n; j++) {
			mark[j] = 0;
		}
		for (int j = i; j >= 0; j--) {
			if (br[j] > 0 && mark[j] == 0) {
				int tmp = br[j];
				int val = 1;
				for (int k = j; k <= i && val; k++) {
					if (mark[k] != 1) tmp += ar[k];
					if (tmp < 0) val = 0;
				}
				if (val) {
					for (int k = j; k <= i; k++) mark[k] = 1;
					ans.push_back(id[j]);
				}
				else {
					last.push(id[j]);
				}
			}
		}
		for (int j = i; j < n; j++) {
			if (br[j] > 0 && mark[j] == 0) {
				int tmp = br[j];
				int val = 1;
				for (int k = j; k >= i && val; k--) {
					if (mark[k] != 1) tmp += ar[k];
					if (tmp < 0) val = 0;
				}
				if (val) {
					for (int k = i; k <= j; k++) mark[k] = 1;
					ans.push_back(id[j]);
				}
				else {
					last.push(id[j]);
				}
			}
		}
		val = 1;
		for (int j = L; j <= R; j++) {
			if (mark[j] != 1) {
				val = 0;
				break;
			}
		}
		if (val) {
			printf("%d\n", i+1);
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			while (!last.empty()) {
				printf("%d ", last.top());
				last.pop();
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
}