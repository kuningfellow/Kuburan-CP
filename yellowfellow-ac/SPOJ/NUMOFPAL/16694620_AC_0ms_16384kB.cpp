#include<bits/stdc++.h>
using namespace std;
char str[1001];
int main() {
	scanf("%s", str);
	int n = strlen(str);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; i - j >= 0 && i + j < n; j++) {
			if (str[i - j] != str[i + j]) break;
			ans++;
		}
		for (int j = 0; i - j >= 0 && i + j + 1< n; j++) {
			if (str[i - j] != str[i + j + 1]) break;
			ans++;
		}
	}
	printf("%lld\n", ans);
}