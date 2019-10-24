#include<stdio.h>
#include<complex>
#include<math.h>

using namespace std;

namespace fft {
	typedef complex<double> comp;
	int bitrev[1 << 18];
	const double PI = acos(-1);
	int revbit(int x, int b) {
		int ret = 0;
		for (int i = 0; i < b; i++) {
			ret <<= 1;
			ret |= (x & 1);
			x >>= 1;
		}
		return ret;
	}
	void init() {
		for (int i = (1 << 18)- 1; i >= 0; i--) {
			bitrev[i] = revbit(i, 18);
		}
	}
	void fft(comp *ar, int mode) {
		for (int i = (1 << 18) - 1; i >= 0; i--) {
			if (bitrev[i] > i) swap(ar[i], ar[bitrev[i]]);
		}
		for (int i = 1; (1 << i) <= (1 << 18); i++) {
			int l = (1 << i);
			comp base(cos(2*PI/l), mode * sin(2*PI/l));
			comp cur(1, 0);
			for (int j = 0; j < l/2; j++) {
				for (int k = 0; k < (1 << 18); k += l) {
					comp A = ar[k + j];
					comp B = cur * ar[k + j + l/2];
					ar[k + j] = A + B;
					ar[k + j + l/2] = A - B;
				}
				cur *= base;
			}
		}
	}
	void convolve(comp *ar, comp *br) {
		for (int i = (1 << 18) - 1; i >= 0; i--) {
			ar[i] = ar[i] * br[i];
		}
	}
}

fft::comp ar[1 << 18];
long long int cnt[1 << 18];

int main() {
	fft::init();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x + 50000]++;
	}
	for (int i = (1 << 18) - 1; i >= 0; i--) {
		ar[i] = fft::comp(cnt[i], 0);
	}
	fft::fft(ar, 1);
	fft::convolve(ar, ar);
	fft::fft(ar, -1);
	long long int ans = 0;
	for (int i = 0; i <= 200000; i++) {
		long long int tmp = (long long int) (ar[i].real() / (1 << 18) + 0.5);
		if (tmp > 0) {
			int num = i - 100000;
			if (num < -50000 || num > 50000) continue;
			if (i % 2 == 0) tmp -= cnt[num / 2 + 50000];
			tmp *= cnt[num + 50000];
			if (num) tmp -= 2 * cnt[50000] * cnt[num + 50000];
			ans += tmp;
		}
	}
	ans -= 2 * (cnt[50000] * (cnt[50000] - 1));
	printf("%lld\n", ans);
	return 0;
}