#include <bits/stdc++.h>
using namespace std;
struct point{
	double x;
	double y;
};
int main(){
	point one, two;
	cin>>one.x>>one.y>>two.x>>two.y;
	double t;
	double v;
	cin>>v>>t;
	double vx,vy,wx,wy;
	cin>>vx>>vy>>wx>>wy;
	double l=0;
	double r=(1<<28);
	double mid;
	double ans;
	double dist;
	point now;
	for (int i=0;i<100;i++){
		mid=(l+r)/2;
		now=one;
		now.x+=vx*min(mid,t);
		now.y+=vy*min(mid,t);
		now.x+=wx*max((double)0,mid-t);
		now.y+=wy*max((double)0,mid-t);
		dist=sqrt((two.x-now.x)*(two.x-now.x)+(two.y-now.y)*(two.y-now.y));
		if (dist<=v*mid){
			ans=mid;
			r=mid;
		}
		else{
			l=mid;
		}
	}
	printf ("%.15f\n",ans);
}