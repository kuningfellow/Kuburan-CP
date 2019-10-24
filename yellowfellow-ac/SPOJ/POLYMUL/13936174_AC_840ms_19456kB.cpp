#include <bits/stdc++.h>
using namespace std;
struct comp{
	double re;
	double im;
};
vector<comp> fft(int x, vector<int>&ply){
	if (x==1){
		comp rett;
		rett.re=ply[0];
		rett.im=0;
		vector<comp>balik;
		balik.push_back(rett);
		return balik;
	}
	comp root[x/2];
	double pi=acos(-1);
	for (int i=0;i<x/2;i++){
		root[i].re=cos(2*pi/x*i);
		root[i].im=sin(2*pi/x*i);
	}
	vector<int>rem;
	vector<int>ram;
	for (int i=0;i<x;i++){
		if (i%2==0){
			rem.push_back(ply[i]);
		}
		else ram.push_back(ply[i]);
	}
	vector<comp>rrem;
	vector<comp>rram;
	vector<comp>ret;
	comp temp;
	temp.re=0;
	temp.im=0;
	for (int i=0;i<x;i++){
		ret.push_back(temp);
	}
	rrem=fft(x/2,rem);
	rram=fft(x/2,ram);
	for (int i=0;i<x/2;i++){
		double real=root[i].re*rram[i].re-root[i].im*rram[i].im;
		double imag=root[i].im*rram[i].re+root[i].re*rram[i].im;
		ret[i].re=rrem[i].re+real;
		ret[i].im=rrem[i].im+imag;
		ret[i+x/2].re=rrem[i].re-real;
		ret[i+x/2].im=rrem[i].im-imag;
	}
	return ret;
}
vector<comp> ifft(int x, vector<comp>&ply){
	if (x==1){
		return ply;
	}
	comp root[x/2];
	double pi=acos(-1);
	for (int i=0;i<x/2;i++){
		root[i].re=cos(2*pi/x*(-i));
		root[i].im=sin(2*pi/x*(-i));
	}
	vector<comp>rem;
	vector<comp>ram;
	for (int i=0;i<x;i++){
		if (i%2==0){
			rem.push_back(ply[i]);
		}
		else ram.push_back(ply[i]);
	}
	vector<comp>rrem;
	vector<comp>rram;
	vector<comp>ret;
	comp temp;
	temp.re=0;
	temp.im=0;
	for (int i=0;i<x;i++){
		ret.push_back(temp);
	}
	rrem=ifft(x/2,rem);
	rram=ifft(x/2,ram);
	for (int i=0;i<x/2;i++){
		double real=root[i].re*rram[i].re-root[i].im*rram[i].im;
		double imag=root[i].im*rram[i].re+root[i].re*rram[i].im;
		ret[i].re=(rrem[i].re+real);
		ret[i].im=(rrem[i].im+imag);
		ret[i+x/2].re=(rrem[i].re-real);
		ret[i+x/2].im=(rrem[i].im-imag);
	}
	return ret;
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n;
		scanf("%d",&n);
		n++;
		vector<int>rem;
		vector<int>ram;
		int s=1;
		while (s<n){
			s*=2;
		}
		int tem=s;
		s*=2;
		for (int i=0;i<s-n;i++){
			rem.push_back(0);
			ram.push_back(0);
		}
		for (int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			rem.push_back(a);
		}
		for (int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			ram.push_back(a);
		}
		vector<comp>rrem;
		vector<comp>rram;
		rrem=fft(s,rem);
		rram=fft(s,ram);
		for (int i=0;i<s;i++){
			double real=rrem[i].re*rram[i].re-rrem[i].im*rram[i].im;
			double imag=rrem[i].re*rram[i].im+rrem[i].im*rram[i].re;
			rrem[i].re=real;
			rrem[i].im=imag;
		}
		rram=ifft(s,rrem);
		for (int i=s-n*2;i<s-1;i++){
			printf ("%.0f",rram[i].re/s);
			if (i!=s-2)printf (" ");
		}
		printf ("\n");
	}
}