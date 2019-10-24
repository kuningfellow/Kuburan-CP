#include<bits/stdc++.h>
using namespace std;
char str[21];
int main() {
	int n;
	scanf("%d", &n);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		int add = 0;
		for (int j = 0; str[j] != '\0' && !add; j++) {
			if (str[j] == '+') add = 1;
		}
		add++;
		tot += add;
	}
	tot += 2;
	tot = tot == 13 ? tot + 1 : tot;
	printf("%d\n", tot * 100);
}