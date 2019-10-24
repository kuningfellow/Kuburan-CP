//UVA 10313 Pay the Price
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL dp[301][301];
int main() {
	dp[0][0] = 1;
	for (int i = 1; i <= 300; i++) {
		for (int j = i; j <= 300; j++) {
			for (int k = 1; k <= 300; k++) {
				dp[j][k] += dp[j - i][k - 1];
			}
		}
	}
	char str[50];
	while (scanf("%[^\n]", str) != EOF) {
		getchar();
		vector<int>lis;
		int tmp = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				tmp = 10 * tmp + str[i] - '0';
			}
			else {
				lis.push_back(tmp);
				tmp = 0;
			}
		}
		lis.push_back(tmp);
		LL ans = 0;
		if (lis.size() == 1) {
			for (int i = 0; i <= 300; i++) {
				ans += dp[lis[0]][i];
			}
		}
		else if (lis.size() == 2) {
			for (int i = 0; i <= min(lis[1], 300); i++) {
				ans += dp[lis[0]][i];
			}
		}
		else {
			for (int i = lis[1]; i <= min(lis[2], 300); i++) {
				ans += dp[lis[0]][i];
			}
		}
		printf("%lld\n", ans);
	}
}