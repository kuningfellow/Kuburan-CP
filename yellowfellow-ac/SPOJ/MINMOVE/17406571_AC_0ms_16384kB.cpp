//SPOJ MINMOVE
#include<bits/stdc++.h>
using namespace std;
char str[100005];
int bad[100005];
int main() {
	scanf("%s", str);
	char best = 'z';
	int l = strlen(str);
	for (int i = 0; i < l; i++) {
		best = min(best, str[i]);
	}
	queue<pair<int,int> >q;
	stack<int>tmp;
	for (int i = 0; i < l; i++) {
		if (i > 0 && str[i-1] == str[i]) continue;
		if (str[i] == best) tmp.push(i), bad[i] = 1;
	}
	while (!tmp.empty()) {
		q.push(pair<int,int>(tmp.top(), tmp.top()));
		tmp.pop();
	}
	while (q.size() > 1) {
		int siz = q.size();
		best = 'z';
		for (int i = 0; i < siz; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (bad[y] == -1) {
				if (q.size() == 0) {
					q.push(pair<int,int>(x, y));
					break;
				}
				continue;
			}
			best = min(best, str[(x + 1) % l]);
			q.push(pair<int,int>(x, y));
		}
		if (q.size() == 1) break;
		siz = q.size();
		for (int i = 0; i < siz; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (str[(x + 1) % l] == best) {
				if (bad[(x + 1) % l] != 0) bad[(x + 1) % l] = -1;
				q.push(pair<int,int>((x + 1) % l, y));
			}
		}
	}
	printf("%d\n", q.front().second);
	return 0;
}