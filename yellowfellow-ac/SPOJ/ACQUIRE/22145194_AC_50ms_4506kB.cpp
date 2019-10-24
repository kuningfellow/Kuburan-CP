// li chao
#define DEBUG(...)
/*                        Strip me down and go to town                        */
/*                          Lick me over upside down                          */
/*                     Pound and pound and pound and pound                    */
/*                        Baby make me make that sound                        */
/*                Aaah, aaah, aaah, aaah, aaaaaaaaaaaaaaaaaah!                */
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> >lis, eval;

typedef long long int TD;
const TD INF = 10000000000000;
namespace LICHAO {
	struct Node {
		TD m, c;
		Node *l, *r;
	};
	Node *newNode(Node *x = NULL) {
		Node *ret = (Node*)malloc(sizeof(Node));
		if (x) ret->m = x->m, ret->c = x->c;
		ret->l = ret->r = NULL;
		return ret;
	}
	void update(Node *k, TD l, TD r, TD m, TD c) {
		TD mid = l + r >> 1;
		bool le = m*l + c < k->m*l + k->c;
		bool ri = m*mid + c < k->m*mid + k->c;
		if (ri) swap(k->m, m), swap(k->c, c);
		if (r - l <= 1) return;
		else if (le != ri) update((k->l)?(k->l):(k->l=newNode(k)), l, mid, m, c);
		else update((k->r)?(k->r):(k->r=newNode(k)), mid, r, m, c);
	}
	TD query(Node *k, TD l, TD r, TD p) {
		if (!k) return INF;
		if (r - l <= 1) return p*k->m + k->c;
		if (p < (l+r >> 1)) return min(p*k->m + k->c, query(k->l, l, l+r>>1, p));
		else return min(p*k->m + k->c, query(k->r, l+r>>1, r, p));
	}
}

int main() {
	int n, maxi = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lis.push_back(pair<int,int>(a, b));
		maxi = max(maxi, b);
	}
	sort(lis.begin(), lis.end());
	for (int i = lis.size() - 1, j = lis.size() - 1; i >= 0; i--) {
		if (i == lis.size() - 1) {
			eval.push_back(lis[i]);
		} else if (lis[i].first <= lis[j].first && lis[i].second <= lis[j].second) {
			continue;
		} else {
			j = i;
			eval.push_back(lis[i]);
		}
	}
	LICHAO::Node *root = LICHAO::newNode();
	for (int i = 0; i < eval.size(); i++) {
		if (i == 0) {
			root->m = eval[i].first;
			root->c = 0;
		} else {
			double c = LICHAO::query(root, 0, 2000000, eval[i-1].second);
			LICHAO::update(root, 0, 2000000, eval[i].first, c);
		}
	}
	printf("%lld\n", LICHAO::query(root, 0, 2000000, maxi));
	return 0;
}