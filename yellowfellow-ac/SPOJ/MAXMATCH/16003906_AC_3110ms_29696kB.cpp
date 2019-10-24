//SPOJ MAXMATCH -- Maximum Self-Matching
//fft
#include<bits/stdc++.h>
using namespace std;
const int N = 262144;
const double PI = acos(-1);
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
};
comp temp[N];
comp ar[N], br[N];
void fft(comp* arr, int n, int mode){
	if (n == 1) return;
	comp base;
	base.re = cos(2 * PI / n);
	base.im = sin(2 * PI / n);
	if (mode == 1) base.im *= -1;
	comp cur;
	cur.re = 1;
	cur.im = 0;
	int dnc = n/2;
	for (int i = 0; i < dnc; i++)
		temp[i] = arr[i*2 + 1];
	for (int i = 0; i < dnc; i++)
		arr[i] = arr[i*2];
	for (int i = dnc; i < n; i++)
		arr[i] = temp[i - dnc];
	fft(arr, dnc, mode);
	fft(arr + dnc, dnc, mode);
	for (int i = 0; i < dnc; i++) {
		comp A = arr[i];
		comp B = arr[i+dnc] * cur;
		arr[i] = A + B;
		arr[i+dnc] = A - B;
		cur = cur * base;
	}
}
int getord(int x){
	int ret = 0;
	while ((1 << ret) < x) ret++;
	return ret;
}
void reset(){
	for (int i = 0; i < N; i++) {
		ar[i].re = ar[i].im = br[i].re = br[i].im = 0;
	}
}
int ans[N];
char rem[100005];
int main(){
	scanf("%s", rem);
	int l = strlen(rem);
	reset();
	int L = (1 << getord(l)) * 2;
	for (int k = 0; k < 3; k++) {
		reset();
		for (int i = 0; i < l; i++) {
			if (rem[i] == k + 'a'){
				ar[i].re = 1;
				br[l - i - 1].re = 1;
			}
		}
		fft(ar, L, 0), fft(br, L, 0);
		for (int i = 0; i < L; i++) {
			ar[i] = ar[i] * br[i];
		}
		fft(ar, L, 1);
		for (int i = 0; i < l; i++) {
			ans[i] += (int)((ar[i+(l-1)].re + 0.5) / L);
		}
	}
	int maxi = 0;
	for (int i = 1; i < l; i++) {
		maxi = max(maxi, ans[i]);
	}
	printf("%d\n", maxi);
	int fir = 1;
	for (int i = 1; i < l; i++) {
		if (ans[i] == maxi) {
			if (!fir) printf(" ");
			printf("%d", i);
			fir = 0;
		}
	}
	printf("\n");
}