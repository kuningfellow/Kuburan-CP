#include <bits/stdc++.h>
using namespace std;
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
void fft(comp *ar, int n, int mode){
	if (n==1)return;
	comp root[n/2];
	int m=1;
	if (mode==1)m=-1;
	for (int i=0;i<n/2;i++){
		root[i].re=cos(2*pi*i*m/n);
		root[i].im=sin(2*pi*i*m/n);
	}
	comp temp[n/2];
	for (int i=0;i<n/2;i++){
		temp[i]=ar[i*2+1];
	}
	for (int i=0;i<n/2;i++){
		ar[i]=ar[i*2];
	}
	for (int i=0;i<n/2;i++){
		ar[i+n/2]=temp[i];
	}
	fft(ar,n/2,mode);
	fft(ar+n/2,n/2,mode);
	for (int i=0;i<n/2;i++){
		comp a=ar[i];
		comp b=ar[i+n/2];
		ar[i]=a+(root[i]*b);
		ar[i+n/2]=a-(root[i]*b);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
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
		for (int i=0;i<p;i++){
			fir[i]=fir[i]*sec[i];
		}
		fft(fir,p,1);
		for (int i=(n-1)*2;i>=0;i--){
			printf ("%.0f",fir[i].re/p);
			if (i!=0)printf (" ");
			else printf ("\n");
		}
	}
}