#include<stdio.h>
#include<stdlib.h>
struct trie {
	int flag;
	trie* nxt[10];
};
class solution {
private:
	trie* head;
	int yes = 1;
	char str[11];
public:
	solution() {
		int tc;
		scanf("%d", &tc);
		while (tc--) {
			yes = 1;
			head = makenode();
			int n;
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {

				scanf("%s", str);
				if (yes) build(head, 0);
			}
			printf("%s\n", yes ? "YES" : "NO");
			kill(head);
		}
	}
	trie* makenode() {
		trie* ret = (trie*)malloc(sizeof(trie));
		ret->flag = 0;
		for (int i = 0; i < 10; i++) ret->nxt[i] = NULL;
		return ret;
	}
	void kill(trie* cur) {
		if (cur == NULL) return;
		for (int i = 0; i < 10; i++) kill(cur->nxt[i]);
		free(cur);
	}
	int to(char c) {
		return c - '0';
	}
	void build(trie* cur, int k) {
		if (cur->flag == 2) {
			yes = 0;
			return;
		}
		if (str[k] == '\0') {
			if (cur->flag != 0) yes = 0;
			cur->flag = 2;
			return;
		}
		cur->flag = 1;
		if (cur->nxt[to(str[k])] == NULL) {
			cur->nxt[to(str[k])] = makenode();
		}
		build(cur->nxt[to(str[k])], k + 1);
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif