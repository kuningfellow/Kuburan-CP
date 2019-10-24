#include <bits/stdc++.h>
using namespace std;
double ar[60005];
double v[60005];
int n;
double func(double pos){
	double sum=0;
	double temp;
	for (int i=0;i<n;i++){
		temp=max(pos-ar[i],ar[i]-pos);
		sum=max(sum,temp/v[i]);
	}
	return sum;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%lf",&ar[i]);
	}
	for (int i=0;i<n;i++){
		scanf("%lf",&v[i]);
	}
	double l=1,r=1000000000,mid1,mid2;
	for (int i=0;i<1000;i++){
		mid1=(l*2+r)/3;
		mid2=(l+2*r)/3;
		if (func(mid1)>func(mid2)){
			l=mid1;
		}
		else{
			r=mid2;
		}
	}
	printf ("%.9f\n",func((l+r)/2));
}