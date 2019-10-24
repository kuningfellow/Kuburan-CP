//UVA 12879 Golf Bot
//bit reversal fft
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 524288;
const int logN = 20;
struct comp {
	double re, im;
	comp operator*(const comp& a){
		comp ret;
		ret.re = re * a.re - im * a.im;
		ret.im = re * a.im + im * a.re;
		return ret;
	}
	comp operator+(const comp& a){
		comp ret;
		ret.re = re + a.re;
		ret.im = im + a.im;
		return ret;
	}
	comp operator-(const comp& a){
		comp ret;
		ret.re = re - a.re;
		ret.im = im - a.im;
		return ret;
	}
	comp() {
		re = 0;
		im = 0;
	}
	comp(double a, double b) {
		re = a;
		im = b;
	}
};
comp temp[N];
comp mat[N];
int vis[N];
int getpow(int x) {
	int ret = 0;
	while ((1 << ret) < x) ret++;
	return ret;
}
int rev(int x, int p){
	int ret = 0;
	for (int i = 0, j = 1; i < p; i++, j <<= 1)
		if ((x & j) > 0) ret |= (1 << (p - 1 - i));
	return ret;
}
void fft(comp* ar, int n, int mode){
	int p = getpow(n);
	for (int i = 0; i < n; i++)
		temp[i] = ar[rev(i, p)];
	for (int i = 1; i <= p; i++) {
		int len = (1 << (i - 1));
		comp base(cos(pi/len), sin(pi/len));
		if (mode) base.im *= -1;
		comp cur(1, 0);
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
	for (int i = 0; i < n; i++)
		ar[i] = temp[i];
}
int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<524288;i++){
			mat[i].re=0;
			mat[i].im=0;
			vis[i]=0;
		}
		int a,q,cnt=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			mat[a].re=1;
		}
		scanf("%d",&q);
		for (int i=0;i<q;i++){
			scanf("%d",&a);
			vis[a]=1;
		}
		for (int i=0;i<524288;i++){
			if (mat[i].re>1e-6){
				cnt+=vis[i];
				vis[i]=0;
			}
		}
		fft(mat,524288,0);
		for (int i=0;i<524288;i++){
			mat[i]=mat[i]*mat[i];
		}
		fft(mat,524288,1);
		for (int i=0;i<524288;i++){
			if (mat[i].re>1e-6){
				cnt+=vis[i];
				vis[i]=0;
			}
		}
		printf ("%d\n",cnt);
	}
}