#include<stdio.h>
#include<vector>

using namespace std;

typedef long long int LL;

LL A[100005];
LL B[100005];

vector<int>love;
LL zero_two[100005];

bool pop(int i, int p1, int p2) {
	double x1 = ((double)zero_two[i] - zero_two[p1]) / (B[p1] - B[i]);
	double x2 = ((double)zero_two[i] - zero_two[p2]) / (B[p2] - B[i]);
	return x1 < x2;
}

LL o_pie(int i, int j) {
	return zero_two[j] + B[j] * (A[i] - 1) + B[i];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &A[i + 1]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &B[i + 1]);
	}
	B[0] = 2000000000ll;
	love.push_back(0);
	int darling = 0;
	for (int i = 1; i <= n; i++) {
		zero_two[i] = o_pie(i, love[darling]);
		while (darling + 1 < love.size() && zero_two[i] > o_pie(i, love[darling + 1])) {
			darling++;
			zero_two[i] = o_pie(i, love[darling]);
		}
		while (love.size() > 1) {
			int p1 = love[love.size() - 1];
			love.pop_back();
			int p2 = love[love.size() - 1];
			if (p2 == 0 || !pop(i, p1, p2)) {
				love.push_back(p1);
				break;
			}
		}
		love.push_back(i);
	}
	printf("%lld\n", zero_two[n]);
	return 0;
}