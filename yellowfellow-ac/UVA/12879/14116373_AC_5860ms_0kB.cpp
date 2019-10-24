#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
complex<double> temp[524288];
void fft(complex<double>* ar, int n, int mode){
	if (n==1)return;
	complex<double> x;
	x.real(1);
	x.imag(0);
	complex<double> prog;
	prog.real(cos(2*pi/n));
	if (mode==0){
		prog.imag(sin(2*pi/n));
	}
	else{
		prog.imag(sin(-2*pi/n));
	}
	for (int i=0;i<n/2;i++){
		temp[i]=ar[i*2+1];
	}
	for (int i=0;i<n/2;i++){
		ar[i]=ar[i*2];
	}
	for (int i=0;i<n/2;i++){
		ar[i+n/2]=temp[i];
	}
	complex<double> a,b;
	fft(ar,n/2,mode);
	fft(ar+n/2,n/2,mode);
	for (int i=0;i<n/2;i++){
		a=ar[i];
		b=ar[i+n/2];
		ar[i]=a+(x*b);
		ar[i+n/2]=a-(x*b);
		x=x*prog;
	}
}
complex<double> mat[524288];
int vis[524288];
int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<524288;i++){
			mat[i].real(0);
			mat[i].imag(0);
			vis[i]=0;
		}
		int a,q,cnt=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			mat[a].real(1);
		}
		scanf("%d",&q);
		for (int i=0;i<q;i++){
			scanf("%d",&a);
			vis[a]=1;
		}
		for (int i=0;i<524288;i++){
			if (mat[i].real()>1e-6){
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
			if (mat[i].real()>1e-6){
				cnt+=vis[i];
				vis[i]=0;
			}
		}
		printf ("%d\n",cnt);
	}
}