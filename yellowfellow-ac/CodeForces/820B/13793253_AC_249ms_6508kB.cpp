#include <bits/stdc++.h>
using namespace std;
struct point{
	double x;
	double y;
};
double ang(point a, point b){
	double A=sqrt(a.x*a.x+a.y*a.y);
	double B=sqrt(b.x*b.x+b.y*b.y);
	double dot=a.x*b.x+a.y*b.y;
	dot=acos(dot/A/B);
	if (dot<0)dot=-dot;
	return dot;
}
double delta(double a, double b){
	a-=b;
	if (a<0)return -a;
	return a;
}
int main(){
	int n,need;
	cin>>n>>need;
	double rec=acos(-1)*need/180;
	double inc=2*acos(-1)/n;
	int ans[3];
	ans[1]=1;
	double close=(1<<28);
	double pick;
	point a;
	a.x=0;
	a.y=0;
	vector<point>vec;
	for (int i=0;i<n-1;i++){
		a.x+=cos(inc*i);
		a.y+=sin(inc*i);
		vec.push_back(a);
	}
	for (int i=0;i<n-2;i++){
		int l=i+1;
		int r=n-2;
		int mid;
		double temp;
		double check;
		while (l<=r){
			mid=(l+r)/2;
			temp=ang(vec[i],vec[mid]);
			check=delta(temp,rec);
			if (check<close){
				close=check;
				pick=temp;
				ans[0]=n-i;
				ans[2]=n-mid;
			}
			if (temp>rec){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	printf ("%d %d %d\n",ans[0],ans[1],ans[2]);
}