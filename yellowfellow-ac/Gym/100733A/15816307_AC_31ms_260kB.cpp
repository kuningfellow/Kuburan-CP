#include<bits/stdc++.h>
using namespace std;
double pi = acos(-1);
int main(){
	int n, r, R;
	cin>>n>>r>>R;
	double deg = pi/n;
	double ar = r*sin(deg)*R/2;
	printf ("%.9f\n", ar*n*2);
}