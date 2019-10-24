#include <bits/stdc++.h>
using namespace std;
const int N = 32768;
const int logN = 16;
const double pi=acos(-1);
struct comp{
	double re;
	double im;
	comp operator*(const comp& a)const{
		comp ret;
		ret.re=re*a.re - im*a.im;
		ret.im=im*a.re + re*a.im;
		return ret;
	}
	comp operator+(const comp& a)const{
		comp ret;
		ret.re=re+a.re;
		ret.im=im+a.im;
		return ret;
	}
	comp operator-(const comp& a)const{
		comp ret;
		ret.re=re-a.re;
		ret.im=im-a.im;
		return ret;
	}
};
comp temp[N];
int bitflip[logN][N];
int getpow(int x){
	int ret = 0;
	while ( (1 << ret) < x ) ret++;
	return ret;
}
int rev(int x, int p){
	int ret = 0;
	for (int i = 0; i < p; i++) {
		ret |= (((x&(1<<(p-i-1)))>0)<<i);
	}
	return ret;
}
void precbit(){
	for (int i = 0; i < logN; i++) {
		for (int j = 0; j < (1<<i); j++) {
			bitflip[i][j] = rev(j, i);
		}
	}
}
void fft(comp* ar, int n, int mode){
	int p = getpow(n);
	for (int i = 0; i < n; i++) {
		temp[bitflip[p][i]] = ar[i];
	}
	for (int i = 1; i <= p; i++) {
		int len = (1 << (i - 1));
		comp base;
		base.re = cos(2*pi/(1<<i));
		base.im = sin(2*pi/(1<<i));
		if (mode) base.im *= -1;
		comp cur;
		cur.re = 1;
		cur.im = 0;
		for (int k = 0; k < len; k++) {
			for (int j = 0; j < n; j += len * 2) {
				comp A = temp[j + k];
				comp B = cur * temp[j + k + len];
				temp[j + k] = A + B;
				temp[j + k + len] = A - B;
			}
			cur = cur * base;
		}
	}
	for (int i = 0; i < n; i++) {
		ar[i] = temp[i];
	}
}
void convolve(int l, comp* ar, comp* br){
	for (int i = 0; i < l; i++) {
		ar[i] = ar[i] * br[i];
	}
}
int main(){
	precbit();
	int tc;
	cin>>tc;
	while (tc--){
		int n;
		cin>>n;
		n++;
		int p=1;
		while (p<n){
			p*=2;
		}
		p*=2;
		comp fir[p];
		comp sec[p];
		for (int i=0;i<p;i++){
			fir[i].re=fir[i].im=0;
			sec[i].re=sec[i].im=0;
		}
		for (int i=0;i<n;i++){
			scanf("%lf",&fir[n-1-i]);
		}
		for (int i=0;i<n;i++){
			scanf("%lf",&sec[n-1-i]);
		}
		fft(fir,p,0);
		fft(sec,p,0);
		convolve(p, fir, sec);
		fft(fir,p,1);
		for (int i=(n-1)*2;i>=0;i--){
			printf ("%.0f",fir[i].re/p);
			if (i!=0)printf (" ");
			else printf ("\n");
		}
	}
	return 0;
}