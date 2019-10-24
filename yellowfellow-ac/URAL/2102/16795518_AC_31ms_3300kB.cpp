#include<bits/stdc++.h>
using namespace std;
const int N = 2000000;
bool isprime[N];
vector<int>lis;
void sieve() {
	for (int i = 2; i < N; i++) {
		if (isprime[i] == 0) {
			lis.push_back(i);
			for (int j = i * 2; j < N; j += i) {
				isprime[j] = 1;
			}
		}
	}
}
bool check(long long int base, int p, long long int target) {
	long long int ret = 1;
	for (int i = 0; i < p; i++) {
		ret *= base;
		if (ret > target) return true;
	}
	return false;
}
int main() {
	sieve();
	long long int n;
	scanf("%lld", &n);
	int cnt = 20;
	for (int i = 0; i < lis.size() && n > 1; i++) {
		if (check(lis[i], cnt, n)) {
			cnt = -1;
			break;
		}
		while (n % lis[i] == 0) {
			cnt--;
			n /= lis[i];
		}
	}
	if (n > 1) cnt--;
	printf("%s\n", cnt == 0 ? "Yes" : "No");
}
