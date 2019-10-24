#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n;
	int ar[n];
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	cin>>m;
	int p1=0,a;
	for (int i=0;i<m;i++){
		cin>>a;
		p1=max(p1,a);
	}
	cin>>k;
	int p2=(1<<30);
	for (int i=0;i<k;i++){
		cin>>a;
		p2=min(p2,a);
	}
	int r1=ar[n-1];
	int wa,wb;
	cin>>wa>>wb;
	double l=0,r=50000,mid,ans;
	for (int i=0;i<1000;i++){
		mid=(l+r)/2;
		if (p1*(r1*r1-mid*mid)/(p2*(mid*mid))<(double)wa/wb){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	printf ("%.9f\n",l);
}