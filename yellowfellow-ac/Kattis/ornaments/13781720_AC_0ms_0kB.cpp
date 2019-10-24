#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		double r,h,s;
		cin>>r>>h>>s;
		if (r==0&&h==0&&s==0)break;
		double rat=1+s/100;
		double side=sqrt(h*h-r*r);
		double len=2*side;
		double sine=side/h;
		double deg=asin(sine);
		double tot=(acos(-1)+(acos(0)-deg)*2)*r+len;
		printf ("%.2f\n",tot*rat);
	}
}