// tes CP cheatsheet
#include <bits/stdc++.h>
using namespace std;

namespace FFT {
  // jangan lupa bagi sama panjang fft
  // jangan lupa init()
  typedef std::complex<double> comp;
  const int maxLogN = 19;
  const double PI = acos(-1);
  int cor[1<<maxLogN][maxLogN+1];
  int getpow(int x) {
    int r = 0;
    while ((1 << r) < x) r++;
    return r;
  }
  int bitrev(int x, int n) {
    int r = 0;
    for (int i = 0; i < n; i++, x >>= 1)
      r <<= 1, r |= (x & 1);
    return r;
  }
  void init() {
    for (int i = 1; i < maxLogN; i++)
      for (int j = 0; j < (1 << i); j++)
        cor[j][i] = bitrev(j, i);
  }
  void fft(comp *ar, int p, int mode) { // 1 for normal, -1 for inverse
    int L = 1 << p;
    for (int i = 0; i < L; i++) if (cor[i][p] > i) swap(ar[i], ar[cor[i][p]]);
    for (int i = 1; i <= p; i++) {
      int l = (1 << i);
      comp base(cos(2*PI/l), mode * sin(2*PI/l));
      comp cur(1, 0);
      for (int j = 0; j < l/2; j++) {
        for (int k = 0; k < L; k += l) {
          comp A = ar[k + j];
          comp B = cur * ar[k + j+l/2];
          ar[k + j] = A + B;
          ar[k + j+l/2] = A - B;
        }
        cur *= base;
      }
    }
  }
  void convolve(comp *ar, comp *br, int p) {
    for (p = 1 << p; p >= 0; p--)
      ar[p] = ar[p] * br[p];
  }
}

char rem[100005];
char ram[100005];
complex<double> fir[1 << 19];
complex<double> sec[1 << 19];
long long int sav[1 << 19];

int main(){
	
	char c[4] = "RPS";
	char cc[4] = "SRP";
	
	int n, m;
	cin >> n >> m;
	scanf("%s", rem);
	scanf("%s", ram);
	FFT::init();
	int p = FFT::getpow(n + m);
	
	for (int j = 0; j < 3; j++){
		
		for (int i = 0; i < 1 << p; i++){
      fir[i] = sec[i] = complex<double>(0, 0);
		}
		for (int i = 0; i < n; i++){
			if (rem[i] == cc[j]){
				fir[n-1-i].real(1);
			}
		}
		for (int i = 0; i < m; i++){
			if (ram[i] == c[j]){
				sec[i].real(1);
			}
		}
		
		FFT::fft(fir, p, 1);
		FFT::fft(sec, p, 1);
    FFT::convolve(fir, sec, p);
		FFT::fft(fir, p, -1);
		
		for (int i = 0; i < 1 << p; i++){
			sav[i] += (long long int)(fir[i].real()/(1 << p) + 0.5);
		}
	}
	long long int ans = 0;
	for (int i = n-1 ; i >= 0; i--){
		ans = max(ans, sav[i]);
	}
	printf ("%lld\n", ans);
}