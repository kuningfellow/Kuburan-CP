#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int N=524288;

struct comp{
	double re;
	double im;
	comp operator*(const comp& a)const{
		comp ret;
		ret.re = re * a.re - im * a.im;
		ret.im = im * a.re + re * a.im;
		return ret;
	}
};

int getord(int x){
	int p = -1;
	while (x > 0){
		x /= 2;
		p++;
	}
	return p;
}

comp temp[N];
void fft(comp *ar, int n, int mode){
	if (n == 1)return;
	
	int m = 1;
	if (mode == 1) m = -1;
	
	int o = getord(n);
	
	comp broot;
	comp croot;
	broot.re = cos(2 * pi / (1<<o) );
	broot.im = sin(2 * pi / (1<<o) );
	croot.re = 1;
	croot.im = 0;
	
	int dnc = n / 2;
	
	for (int i = 0;i < dnc; i++){
		temp[i] = ar[i * 2 + 1];
	}
	for (int i = 0; i < dnc; i++){
		ar[i] = ar[i * 2];
	}
	for (int i = 0; i < dnc; i++){
		ar[i + dnc] = temp[i];
	}
	
	fft(ar, dnc, mode);
	fft(ar + dnc, dnc, mode);
	
	for (int i = 0; i < dnc; i++){
		double aar = ar[i].re;
		double aai = ar[i].im;
		double br = ar[i + dnc].re;
		double bi = ar[i + dnc].im;
		double ror = croot.re;
		double roi = m * croot.im;
		ar[i].re = aar + (ror * br - roi * bi);
		ar[i].im = aai + (ror * bi + roi * br);
		ar[i + dnc].re = aar - (ror * br - roi * bi);
		ar[i + dnc].im = aai - (ror * bi + roi * br);
		croot = croot * broot;
	}
}

char rem[100005];
char ram[100005];
comp fir[N];
comp sec[N];
long long int sav[N];

int main(){
	
	char c[4] = "RPS";
	char cc[4] = "SRP";
	
	int n, m;
	cin >> n >> m;
	scanf("%s", rem);
	scanf("%s", ram);
	
	int p = 1 << getord(n + m);
	if ( p < (n + m) ){
		p *= 2;
	}
	
	for (int j = 0; j < 3; j++){
		
		for (int i = 0; i < p; i++){
			fir[i].re = fir[i].im = 0;
			sec[i].re = sec[i].im = 0;
		}
		for (int i = 0; i < n; i++){
			if (rem[i] == cc[j]){
				fir[n-1-i].re = 1;
			}
		}
		for (int i = 0; i < m; i++){
			if (ram[i] == c[j]){
				sec[i].re = 1;
			}
		}
		
		fft(fir, p, 0);
		fft(sec, p, 0);
		for (int i = 0; i < p; i++){
			fir[i] = fir[i] * sec[i];
		}
		fft(fir, p, 1);
		
		for (int i = 0; i < p; i++){
			sav[i] += ( (long long int) fir[i].re + 1 ) / p;
		}
	}
	long long int ans = 0;
	for (int i = n-1 ; i >= 0; i--){
		ans = max(ans, sav[i]);
	}
	printf ("%lld\n", ans);
}