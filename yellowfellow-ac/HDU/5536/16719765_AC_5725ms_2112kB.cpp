#include<bits/stdc++.h>
using namespace std;
struct trie {
	int cnt;
	trie* zero;
	trie* one;
};
trie* create() {
	trie* ret = (trie*)malloc(sizeof(trie));
	ret->cnt = 0;
	ret->zero = ret->one = NULL;
	return ret;
}
char str[1001][32];
int ar[1001];
void build (trie* node, int p, int idx) {
	if (idx < 0) {
		return;
	}
	if (str[p][idx] == '0') {
		if (node->zero == NULL) {
			node->zero = create();
		}
		node->zero->cnt++;
		build(node->zero, p, idx - 1);
	}
	else {
		if (node->one == NULL) {
			node->one = create();
		}
		node->one->cnt++;
		build(node->one, p, idx - 1);
	}
}
void update(trie* node, int p, int idx, int v) {
	if (idx < 0) return;
	if (str[p][idx] == '0') {
		node->zero->cnt += v;
		update(node->zero, p, idx - 1, v);
	}
	else {
		node->one->cnt += v;
		update(node->one, p, idx - 1, v);
	}
}
char eval[32];
int serc (trie* node, int idx) {
	if (idx < 0) {
		return 0;
	}
	if (eval[idx] == '1') {
		if (node->zero != NULL && node->zero->cnt > 0) return (1 << idx) | serc(node->zero, idx - 1);
		return serc(node->one, idx - 1);
	}
	if (eval[idx] == '0') {
		if (node->one != NULL && node->one->cnt > 0) return (1 << idx) | serc(node->one, idx - 1);
		return serc(node->zero, idx - 1);
	}
}
void clean(trie* node) {
	if (node->one != NULL) clean(node->one);
	if (node->zero != NULL) clean(node->zero);
	free(node);
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		trie* head = create();
		int ans = 0;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ar[i]);
			int tmp = ar[i];
			for (int j = 0; j < 32; j++) {
				str[i][j] = tmp % 2 + '0';
				tmp /= 2;
			}
			build(head, i, 31);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int tmp = ar[i] + ar[j];
				for (int k = 0; k < 32; k++) {
					eval[k] = tmp % 2 + '0';
					tmp /= 2;
				}
				update(head, i, 31, -1);
				update(head, j, 31, -1);
				ans = max(ans, serc(head, 31));
				update(head, i, 31, 1);
				update(head, j, 31, 1);
			}
		}
		printf("%d\n", ans);
		clean(head);
	}
}