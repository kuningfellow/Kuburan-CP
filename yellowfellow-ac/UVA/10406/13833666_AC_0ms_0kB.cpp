#include <bits/stdc++.h>
using namespace std;
struct point{
	double x;
	double y;
};
double cross(point a, point b, point c){
	double u1=c.x-b.x;
	double u2=c.y-b.y;
	double v1=b.x-a.x;
	double v2=b.y-a.y;
	return u1*v2-u2*v1;
}
double dist(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dot(point a, point b, point c){
	double u1=c.x-b.x;
	double u2=c.y-b.y;
	double v1=b.x-a.x;
	double v2=b.y-a.y;
	return u1*v1+u2*v2;
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
		double comp=0;
		double deg;
		double len=0;
		for (int i=0;i<n;i++){
			double cros=cross(ar[i],ar[(i+1)%n],ar[(i+2)%n]);
			double A=dist(ar[i],ar[(i+1)%n]);
			double B=dist(ar[(i+1)%n],ar[(i+2)%n]);
			len+=dist(ar[i],ar[(i+1)%n]);
			if (cros==0)continue;
			deg=dot(ar[i],ar[(i+1)%n],ar[(i+2)%n])/A/B;
			if (cros>0){
				comp+=d*d/tan((acos(-1)-acos(deg))/2);
			}
			else{
				comp-=d*d/tan((acos(-1)-acos(deg))/2);
			}
		}
		double sum1=0;
		double sum2=0;
		for (int i=0;i<n;i++){
			sum1+=ar[i].x*ar[(i+1)%n].y;
			sum2+=ar[i].y*ar[(i+1)%n].x;
		}
		sum1-=sum2;
		sum1=max(sum1,-sum1);
		printf ("%.3lf\n",sum1/2-len*d+comp);
	}
}