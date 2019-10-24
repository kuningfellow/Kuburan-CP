#include <bits/stdc++.h>
using namespace std;
struct point{
	double x;
	double y;
};
double cross(point a, point b, point c){
	double u1=b.x-a.x;
	double u2=b.y-a.y;
	double v1=c.x-b.x;
	double v2=c.y-b.y;
	return u1*v1+u2*v2;
}
double magnitude(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	while (1<2){
		int n;
double d;
		cin>>d>>n;
		if (d==0&&n==0)break;
		point ar[n];
		double red[n];
		for (int i=0;i<n;i++){
			cin>>ar[i].x>>ar[i].y;
		}
		if (n<=2){
			printf ("0\n");
			continue;
		}
		int pick1=-1;
		int pick2=-1;
		double comp=0;
		double deg;
		double len=0;
		for (int i=0;i<n;i++){
			len+=magnitude(ar[i],ar[(i+1)%n]);
			deg=cross(ar[i],ar[(i+1)%n],ar[(i+2)%n])/magnitude(ar[i],ar[(i+1)%n])/magnitude(ar[(i+1)%n],ar[(i+2)%n]);
			if (deg==1)continue;
			deg=acos(-1)-acos(deg);
			comp+=d*d/tan(deg/2);
		}
		double sum1=0;
		double sum2=0;
		for (int i=0;i<n;i++){
			sum1+=ar[i].x*ar[(i+1)%n].y;
			sum2+=ar[i].y*ar[(i+1)%n].x;
		}
		sum1-=sum2;
		sum1=max(sum1,-sum1);
		printf ("%.3f\n",sum1/2-len*d+comp);
	}
}