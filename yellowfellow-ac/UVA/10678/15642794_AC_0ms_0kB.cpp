//UVA 10678 The Grazing Cow
#include<bits/stdc++.h>
using namespace std;
double pi=acos(-1);
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		double c,a;
		cin>>c>>a;
		c/=2;
		a/=2;
		c=sqrt(a*a-c*c);
		printf ("%.3f\n",a*c*pi);
	}
}