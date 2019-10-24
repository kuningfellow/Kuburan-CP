#include<stdio.h>
#include<complex>
#include<math.h>

using namespace std;

namespace fft {
	typedef complex<double> comp;
	const double PI = acos(-1);
	int revbit[1 << 19];
	int getpow(int x) {
		int r = 0;
		while ((1 << r) < x) r++;
		return r;
	}
	int bitrev(int x, int b) {
		int r = 0;
		for (int i = 0; i < b; i++) {
			r <<= 1;
			r |= (x & 1);
			x >>= 1;
		}
		return r;
	}
	void init(int p) {
		for (int i = (1 << p) - 1; i >= 0; i--) {
			revbit[i] = bitrev(i, p);
		}
	}
	void fft(comp* ar, int p, int m) {
		int L = (1 << p);
		for (int i = 0; i < L; i++) {
			if (revbit[i] > i) swap(ar[i], ar[revbit[i]]);
		}
		for (int i = 1; i <= p; i++) {
			int l = (1 << i);
			comp base(cos(2*PI/l), m * sin(2*PI/l));
			comp cur(1, 0);
			for (int j = 0; j < l/2; j++) {
				for (int k = 0; k < L; k += l) {
					comp A = ar[j + k];
					comp B = cur * ar[j + k + l/2];
					ar[j + k] = A + B;
					ar[j + k + l/2] = A - B;
				}
				cur *= base;
			}
		}
	}
	void convolve(comp* ar, comp* br, int p) {
		for (int i = (1 << p) - 1; i >= 0; i--) {
			ar[i] = ar[i] * br[i];
		}
	}
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int min(int a, int b) {
	return -max(-a, -b);
}

const char ite[5] = "ATGC";
int mark[1 << 19];
char S[200005];
char T[200005];
int ans[1 << 19];
fft::comp ar[1 << 19];
fft::comp br[1 << 19];

int main() {
	int n, m, k, tot = 0;
	
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s %s", S, T);
	
	int P = fft::getpow(n + m);
	int L = 1 << P;
	fft::init(P);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			mark[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			if (S[j] == ite[i]) {
				mark[max(0, j - k)]++;
				mark[min(n, j + k + 1)]--;
			}
		}
		for (int j = 0, car = 0; j < L; j++) {
			car += mark[j];
			mark[j] = car;
		}
		
		for (int j = 0; j < L; j++) {
			ar[j] = fft::comp(mark[j] ? 1 : 0, 0);
			br[j] = fft::comp(0, 0);
		}
		for (int j = 0; j < m; j++) {
			if (T[j] == ite[i]) br[m - j - 1] = fft::comp(1, 0);
		}
		
		fft::fft(ar, P, 1);
		fft::fft(br, P, 1);
		fft::convolve(ar, br, P);
		fft::fft(ar, P, -1);
		
		for (int j = m - 1; j < L; j++) {
			ans[j] += (long long int) (ar[j].real() / L + 0.5);
		}
	}
	
	for (int i = m - 1; i < L; i++) {
		if (ans[i] == m) tot++;
	}
	printf("%d\n", tot);
	
	return 0;
}