#include<stdio.h>
#include<utility>
#include<map>

using namespace std;

typedef long long int LL;

LL max(LL a, LL b) {
	if (a > b) return a;
	return b;
}

map<LL,int>ma;

int main() {
	LL C, A, B, X, Y;
	scanf("%lld %lld %lld %lld %lld", &C, &A, &B, &X, &Y);
	LL ans = 0;
	ans = max(ans, A * (C / X) + B * ((C - (C/X*X)) / Y));
	ans = max(ans, B * (C / Y) + A * ((C - (C/Y*Y)) / X));
	
	if (X > 1000000 || Y > 1000000) {
		if (X < Y) {
			X ^= Y ^= X ^= Y;
			A ^= B ^= A ^= B;
		}
		int tmpx = C/X;
		for (int i = 0; tmpx >= 0; i++) {
			int gap = C - tmpx * X - (C - tmpx * X) / Y * Y;
			if (ma[gap] == 2) break;
			ma[gap]++;
			ans = max(ans, tmpx * A + (C - tmpx * X) / Y * B);
			tmpx--;
		}
	}
	else {
		if ((double)A / X < (double) B / Y) {
			X ^= Y ^= X ^= Y;
			A ^= B ^= A ^= B;
		}
		int tmpx = C/X;
		for (int i = 0; tmpx >= 0; i++) {
			int gap = C - tmpx * X - (C - tmpx * X) / Y * Y;
			if (ma[gap] == 2) break;
			ma[gap]++;
			ans = max(ans, tmpx * A + (C - tmpx * X) / Y * B);
			tmpx--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}