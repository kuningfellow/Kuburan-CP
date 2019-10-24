#include<stdio.h>
#include<complex>
#include<math.h>

using namespace std;

namespace fft {
	typedef complex<double> comp;
	int bitrev[1 << 18];
	const double PI = acos(-1);
	int getpow(int x) {
		int r = 0;
		while ((1 << r) < x) r++;
		return r;
	}
	int revbit(int x, int b) {
		int ret = 0;
		for (int i = 0; i < b; i++) {
			ret <<= 1;
			ret |= (x & 1);
			x >>= 1;
		}
		return ret;
	}
	void init(int p) {
		for (int i = (1 << p) - 1; i >= 0; i--) {
			bitrev[i] = revbit(i, p);
		}
	}
	void fft(comp *ar, int p, int mode) {
		int L = 1 << p;
		for (int i = L - 1; i >= 0; i--) {
			if (bitrev[i] > i) swap(ar[i], ar[bitrev[i]]);
		}
		for (int i = 1; i <= p; i++) {
			int l = (1 << i);
			comp base(cos(2*PI/l), mode * sin(2*PI/l));
			comp cur(1, 0);
			for (int j = 0; j < l/2; j++) {
				for (int k = 0; k < L; k += l) {
					comp A = ar[k + j];
					comp B = cur * ar[k + j + l/2];
					ar[k + j] = A + B;
					ar[k + j + l/2] = A - B;
				}
				cur *= base;
			}
		}
	}
	void convolve(comp *ar, comp *br, int p) {
		for (int i = (1 << p) - 1; i >= 0; i--) {
			ar[i] = ar[i] * br[i];
		}
	}
}

fft::comp ar[1 << 18];
long long int cnt[1 << 18];

int main() {
	int n;
	scanf("%d", &n);
	int low = 50000;
	int high = -50000;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x + 50000]++;
		low = min(low, x);
		high = max(high, x);
	}
	for (int i = low; i <= high; i++) {
		ar[i - low] = fft::comp(cnt[i + 50000], 0);
	}
	
	int p = fft::getpow((high - low) * 2);
	fft::init(p);
	fft::fft(ar, p, 1);
	fft::convolve(ar, ar, p);
	fft::fft(ar, p, -1);
	
	long long int ans = 0;
	for (int i = low * 2; i <= high * 2; i++) {
		long long int tmp = (long long int) (ar[i - low*2].real() / (1 << p) + 0.5);
		if (tmp > 0) {
			int num = i;
			if (num < -50000 || num > 50000) continue;
			if (num % 2 == 0) tmp -= cnt[num / 2 + 50000];
			tmp *= cnt[num + 50000];
			if (num) tmp -= 2 * cnt[50000] * cnt[num + 50000];
			ans += tmp;
		}
	}
	ans -= 2 * (cnt[50000] * (cnt[50000] - 1));
	printf("%lld\n", ans);
	return 0;
}