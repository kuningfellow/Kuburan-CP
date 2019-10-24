#include<bits/stdc++.h>
using namespace std;
struct trie{
	int idx;
	trie* zero;
	trie* one;
};
struct trie* newnode(){
	trie* nnode = (struct trie*)malloc(sizeof(trie));
	nnode->zero = NULL;
	nnode->one = NULL;
	nnode->idx = -1;
	return nnode;
}
int serc(trie* node, int d, int v, int& id){
	if (d < 0) {
		id = node->idx;
		return 0;
	}
	if ((v & (1<<d)) > 0) {
		if (node->one != NULL) return serc(node->one, d-1, v, id);
		else return serc(node->zero, d-1, v, id) | (1<<d);
	}
	else {
		if (node->zero != NULL) return serc(node->zero, d-1, v, id);
		else return serc(node->one, d-1, v, id) | (1<<d);
	}
}
void create(trie* node, int d, int v, int id){
	if (d < 0) {
		if (node->idx == -1) node->idx = id;
	}
	else if ((v & (1<<d)) > 0) {
		if (node->one == NULL) {
			node->one = newnode();
		}
		create(node->one, d-1, v, id);
	}
	else{
		if (node->zero == NULL) {
			node->zero = newnode();
		}
		create(node->zero, d-1, v, id);
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int ans = (-1) ^ (1<<31);
	int l, r;
	trie* head = newnode();
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (i > 0) {
			int id;
			int eval = serc(head, 30, a, id);
			if (eval < ans) {
				ans = eval;
				l = id+1;
				r = i+1;
			}
		}
		create(head, 30, a, i);
	}
	printf("%d %d\n", l, r);
}