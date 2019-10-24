#include<stdio.h>
#include<utility>

using namespace std;

pair<int,int> lis[500005];
int siz;
char str[500005];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", str);
		int st = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == 'T') lis[siz++] = pair<int,int>(st, 1);
			else if (str[i] == 'F') lis[siz++] = pair<int,int>(st, 0);
			else if (str[i] == '!') lis[siz++] = pair<int,int>(st, -1);
			else if (str[i] == '(') {
				st++;
			}
			else if (str[i] == ')') {
				int ret = siz;
				int cnt = 0;
				while (siz && lis[siz - 1].first == st) {
					if (lis[siz - 1].second == -3) {
						if (ret > cnt) ret = cnt;
						cnt = 0;
					}
					else if (lis[siz - 1].second == 0) cnt++;
					siz--;
				}
				if (ret > cnt) ret = cnt;
				st--;
				lis[siz++] = pair<int,int>(st, ret > 0 ? 0 : 1);
			}
			else if (str[i] == '&') lis[siz++] = pair<int,int>(st, -2);
			else if (str[i] == '|') lis[siz++] = pair<int,int>(st, -3);
			while (siz > 1) {
				int a = lis[siz - 1].first;
				int b = lis[siz - 1].second;
				siz--;
				if (lis[siz - 1].first == a && b >= 0 && lis[siz - 1].second == -1) {
					lis[siz - 1].second = 1 ^ b;
				}
				else {
					lis[siz++] = pair<int,int>(a, b);
					break;
				}
			}
		}
		int ret = 2;
		int cnt = 0;
		while (siz && lis[siz - 1].first == st) {
			if (lis[siz - 1].second == -3) {
				if (ret > cnt) ret = cnt;
				cnt = 0;
			}
			else if (lis[siz - 1].second == 0) cnt++;
			siz--;
		}
		if (ret > cnt) ret = cnt;
		st--;
		printf("%d\n", ret);
	}
	return 0;
}