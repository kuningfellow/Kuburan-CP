#include<stdio.h>
#include<vector>
using namespace std;
class solution {
private:
	vector<int>lis;
	bool isprime[1121];
	int dp[1121][15];
public:
	solution() {
		sieve();
		reset();
		build();
		while (1 < 2) {
			int n, m;
			scanf("%d %d", &n, &m);
			if (n == 0 && m == 0) break;
			printf("%d\n", dp[n][m]);
		}
	}
	void build() {
		dp[0][0] = 1;
		for (int i = 0; i < lis.size(); i++) {
			for (int j = 14; j > 0; j--) {
				for (int k = 0; k < 1121; k++) {
					if (k - lis[i] >= 0) {
						dp[k][j] += dp[k - lis[i]][j - 1];
					}
				}
			}
		}
	}
	void reset() {
		for (int i = 0; i < 1121; i++) {
			for (int j = 0; j < 15; j++) {
				dp[i][j] = 0;
			}
		}
	}
	void sieve() {
		for (int i = 0; i < 1121; i++) {
			isprime[i] = 0;
		}
		for (int i = 2; i < 1121; i++) {
			if (isprime[i] == 0) {
				lis.push_back(i);
				for (int j = i * 2; j < 1121; j += i) {
					isprime[j] = 1;
				}
			}
		}
	}
};

#ifndef L0C4L
int main() {
	solution();
	return 0;
}
#endif