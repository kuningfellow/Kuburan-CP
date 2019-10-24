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
int getord(int x){
	int p=-1;
	while (x>0){
		x/=2;
		p++;
	}
	return p;
}
comp root[22][2097153];
void prec(){
	for (int i=0;i<22;i++){
		for (int j=0;j<(1<<i);j++){
			root[i][j].re=cos(2*pi*j/(1<<i));
			root[i][j].im=sin(2*pi*j/(1<<i));
		}
	}
}
comp temp[2097153];
void fft(comp *ar, int n, int mode){
	if (n==1)return;
	int m=1;
	if (mode==1)m=-1;
	int o=getord(n);
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
		double aar=ar[i].re;
		double aai=ar[i].im;
		double br=ar[i+n/2].re;
		double bi=ar[i+n/2].im;
		double ror=root[o][i].re;
		double roi=m*root[o][i].im;
		ar[i].re=aar + (ror*br - roi*bi);
		ar[i].im=aai + (ror*bi + roi*br);
		ar[i+n/2].re=aar - (ror*br - roi*bi);
		ar[i+n/2].im=aai - (ror*bi + roi*br);
	}
}
char rem[300005];
char ram[300005];
comp fir[2097152];
comp sec[2097152];
int res[2097152];
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	prec();
	int tc;
	cin>>tc;
	while (tc--){
		scanf("%s",rem);
		scanf("%s",ram);
		int l1=strlen(rem),l2=strlen(ram);
		int l=l1+l2;
		int p=1;
		while (p<l)p*=2;
		p*=2;
		for (int i=0;i<p;i++){
			fir[i].re=fir[i].im=0;
			sec[i].re=sec[i].im=0;
			res[i]=0;
		}
		for (int i=0;i<l1;i++){
			fir[l1-1-i].re=rem[i]-'0';
		}
		for (int i=0;i<l2;i++){
			sec[l2-1-i].re=ram[i]-'0';
		}
		fft(fir,p,0);
		fft(sec,p,0);
		for (int i=0;i<p;i++){
			fir[i]=fir[i]*sec[i];
		}
		fft(fir,p,1);
		int num;
		int car=0;
		for (int i=0;i<p;i++){
			res[i]=(fir[i].re+0.5)/p+car;
			car=res[i]/10;
			res[i]%=10;
		}
		int fir=1;
		for (int i=p-1;i>=0;i--){
			if (res[i]==0&&fir==1)continue;
			else{
				fir=0;
				printf ("%d",res[i]);
			}
		}
		if (fir==1)printf ("0");
		printf ("\n");
	}
}