#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
double G=9.8;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		double a,b,x,y;
		cin>>a>>b>>x>>y;
		a=-a;
		if (a<0&&x>0){
			printf ("0\n");
			continue;
		}
		if (a>0&&x<0){
			printf ("0\n");
			continue;
		}
		double L=sqrt(a*a+b*b);
		double proj=(x*a+y*b)/L;
		double perp=(x*b-y*a)/L;
		if (a<0)a=-a;
		double t=sqrt(2*perp/(G*a/L));
		double A=G*b/L;
		if (A<0){
			A=-A;
		}
		double s=0;
		double sine=b/L;
		int ans=0;
		if (proj<0){
			proj=-proj;
		}
		for (int i=0;i<101;i++){
			if (proj*2>=A*i*i*t*t){
				ans=i;
			}
			else{
				break;
			}
		}
		printf ("%d\n",(ans+1)/2);
	}
}